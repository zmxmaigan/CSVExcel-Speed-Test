#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
using namespace std;

FILE *fp;

int randint_range(int n, int m)
{ // 产生n~m间的随机数（包括m和n）
    long double base = ((long double)rand()) / RAND_MAX;
    long double res = n + (base * (long double)(m - n + 1))+((char)rand());
    return res;
} // 来自：https://www.cnblogs.com/xiaotan-js/p/16687603.html

int main()
{
    cout<<"有以下生成模式，请选择：\n";
    cout<<"===========================================";
    cout<<"\nA.生成一个m*n规模的随机数";
    cout<<"\nB.从文本中生成\n";
	cout<<"===========================================\n";
    char mode;
	system("md txt");
	system("md outfile");
    scanf("%c",&mode);
    switch (mode)
    {
        case 'A':
            cout<<"请输入表格规模（行，列）";
            int m,n;
            cin>>m>>n;
            freopen(".\\outfile\\test.csv","w",stdout);
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    cout<<randint_range(1,(m+n+i+j)*2)<<",";
                }
                cout<<endl;
            }
			system("start .\\outfile\\test.csv");
            break;
		case 'B':
			fp=fopen(".\\txt\\text.txt","r");
			if(fp==NULL){
				cout<<"找不到文件，请将text.txt文件放到.\\txt\\text.txt目录下\n";
				fclose(fp);
				system("pause");
			}else{
				cout<<"请输入数据规模（会生成一个n*n大小的.csv表）";
				int n;
				cin>>n;
				char aaa[114514];
				//char* aaaa[2]=",";
				
				fgets(aaa,255,fp);
				fclose(fp);
				cout<<"正在将\""<<aaa<<"\"写入到.csv文件中...\n";
				
				strcat(aaa,",");
				
				fp=fopen(".\\outfile\\test.csv","w");
				for(int i=1;i<=n;i++){
					for(int j=0;i<=n;i++){
						fprintf(fp,aaa);
					}
					fprintf(fp,"\n");
				}
				fclose(fp);
			}
			break;
        default:
			cout<<"不支持的操作\n";
			system("pause");
            break;
    }
    return 0;
}
