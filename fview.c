#include <stdio.h>
#include <stdlib.h>   //exit()の使用
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>   //ファイル記述子の操作等　open()でも使っている
#include <time.h>

int main(int argc, char *argv[]){

  int i;
  struct stat sb;	// statの構造体を変数sbとする
  int fd;           // ファイル記述子用
  
  // 引数を与えるよう注意
  if(argc==1){printf("Please input view files"); exit(1);} 
  
  // ファイルを開く
  for (i=1;i<argc;i++){
    printf("open file is : %s\n",argv[i]);  // 現在処理中のファイル名を表示

  if ((fd = open(argv[i], O_RDONLY)) == -1) { // 読み込み専用で開く
	perror("open");                           // 開けない場合のエラー処理
	exit(1);
	}

	if (fstat(fd,&sb) == -1) {  // ファイル記述子fdが示す対象の属性を得る。0成功　-1エラー
	     perror("fstat");
	     close(fd);	            //失敗したら、エラーを出力し終了。
	     exit(1);
		} else {              // fstatが成功したとき
		printf("this file type is "); //POSIXマクロはst_modeで使用されるファイル種別の確認ができる
		switch (sb.st_mode & S_IFMT) { //st_modeのフラグを使用してそれぞれファイル種別を表示する。
        case S_IFSOCK: printf("ソケット\n");       break;
		case S_IFLNK: printf("シンボリックリンク\n");   break;
		case S_IFBLK: printf("ブロックデバイス\n");   break;
	    case S_IFDIR: printf("ディレクトリ\n");      break;
	    case S_IFCHR: printf("キャラクターデバイス\n"); break;
		case S_IFIFO: printf("FIFO\n");         break;
		case S_IFREG: printf("通常ファイル\n");		break;	    
	    default:      printf("その他のファイル\n");    break;
	    }
        }
	
	//ファイルのサイズの表示
	    printf("ファイルサイズ: %lld bytes\n",(long long) sb.st_size);
	//最終変更時刻の表示
	    printf("最終変更時刻: %s",ctime(&sb.st_mtime));
	    close(fd);
		puts("");
	
	}
	} 
	