#include <cstdio>
#include <string>
#include <windows.h>
#include <shellapi.h>
#pragma comment(lib,"shell32.lib")
#pragma comment(lib,"User32.lib")
using namespace std;

char default_fileName[] = "setting.txt";

long long lower, higher;

int main()
{
    
    FILE *fileS;
    fileS = fopen(default_fileName, "r");
    if (fileS == NULL)
    {
        printf("Not find the file\n");
        fileS = fopen(default_fileName, "w");
    }
    fileS = fopen(default_fileName, "r");

    ShellExecute(NULL, "open", default_fileName, NULL, NULL, SW_SHOW);
    Sleep(10);
    MessageBox(GetForegroundWindow(), "请在打开的窗口中输入两个区间值\nPS:两个数字由\'~\'连接", "温馨提示:输入后关闭此窗口", MB_OK);
    fscanf(fileS, "%lld~%lld", &lower, &higher);
    printf("Interval:%lld %lld\n", lower, higher);

    
    exit(0);
}
