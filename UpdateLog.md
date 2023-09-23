# **The log——日志**📃

> “The log is the program's eternal memory, recording the team's late night work. A journal is not written for others, it is written for yourself.”

## The v1.0 

1. 文字界面大黑框,基本实现所需内容

   ```c++
   // v1.0
   #define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
   #include <bits/stdc++.h>
   #include <windows.h>
   using namespace std;
   int main() {
   	system("mode con cols = 20 lines = 3");
   	system("title 点这里抽取幸运儿~"); 
   	default_random_engine rand(time(NULL));	
   	uniform_int_distribution<int> rand1(1, 51);
   	while(1){
   		cout << "本轮种子：" << rand() << endl;
   		cout << " 幸运儿 ：" << rand1(rand) << endl; 
   		if(!KEY_DOWN(MOUSE_MOVED))
   			system("cls");
   		else{
   			system("pause");
   		}
   	}
   	return (0);
   }
   ```

**Time：2021-12-05 19:43:28**

## The v2.1

1. 调用API实现图形化界面

   ```c++
   // v2.1
   #define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
   #include <bits/stdc++.h>
   #include <windows.h>
   	char text[13] = "上天眷顾的孩子们名单: ";
   	char num[3],empty;
   	int  flag,test,rom;
   using namespace std;
   int main() { 
   	do
   	{
   		uniform_int_distribution<int> rand1(1, 51);
   		default_random_engine rand(time(NULL));
   		
   		test = rand();
   		rom = rand1(rand);
   		
   		num[0] = ' '; num[1] = ' '; num[2] = ',';
   		num[0] = rom /10 + '0';
   		num[1] = rom %10 + '0';
   		if(num[0] == '0') num[0] = empty; 
   		
   		flag = MessageBox(GetForegroundWindow(),strcat(text,num),"[重试] 再眷顾一个  [取消] 退出程序",MB_ICONQUESTION|MB_RETRYCANCEL);
   		Sleep(100); 
   	}while(flag != 2);
   	return (0);
   }
   
   ```

**Time：2021-12-12 09:39:32**

## The v2.2

1. 完成“筛查去重”算法

2. 修复BUG：无法抽取个位数

   ```c++
   // v2.2
   #define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
   #define MAXN 52
   #include <bits/stdc++.h>
   #include <windows.h>
   	char text[24] = "上天眷顾的孩子们名单: ";
   	char num[3];
   	char empty;
   	int  tong[MAXN] = {};
   	int  flag,test,rom;
   using namespace std;	
   int main() {
   	do
   	{
   		uniform_int_distribution<int> rand1(1, MAXN-1);
   		default_random_engine rand(time(NULL));
   		
   		test = rand();
   		rom = rand1(rand);
   
   		if(tong[rom]){
   			flag = 4;
   			continue;
   		}
   		else if(tong[rom] == 0) tong[rom] = 1;
   		
   		num[0] = ' '; num[1] = ' '; num[2] = ',';
   		num[0] = rom /10 + '0';
   		num[1] = rom %10 + '0';
   	
   		if(num[0] == '0'){
   			num[0] = num[1];
   			num[1] = ',';
   			num[2] = empty;
   		}
   		
   		flag = MessageBox(GetForegroundWindow(),strcat(text,num),"[重试] 再抽一个  [取消] 退出程序",MB_ICONQUESTION|MB_RETRYCANCEL);
   		Sleep(1000); 
   	}while(flag != 2);
   	return (0);
   }
   ```

**Time：2021-12-15 21:59:43**

## The v2.3

1. 优化代码 响应速度加快

   ```c++
   // v2.3
   #define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
   #define MAXN 52
   #include <bits/stdc++.h>
   #include <windows.h>
   	char text[24] = "名单: ";
   	char num[3];
   	char empty;
   	int  tong[MAXN] = {};
   	int  flag,test,rom;
   using namespace std;	
   int main() {
   	uniform_int_distribution<int> rand1(1, MAXN-1);
   	default_random_engine rand(time(NULL));
   	do
   	{	
   		test = rand();
   		rom = rand1(rand);
   
   		if(tong[rom])
   			continue;
   
   		else if(tong[rom] == 0) tong[rom] = 1;
   		
   		num[0] = ' '; num[1] = ' '; num[2] = ',';
   		num[0] = rom /10 + '0';
   		num[1] = rom %10 + '0';
   	
   		if(num[0] == '0'){
   			num[0] = num[1];
   			num[1] = ',';
   			num[2] = empty;
   		}
   		
   		flag = MessageBox(GetForegroundWindow(),strcat(text,num),"[重试] 再抽一个  [取消] 退出程序",MB_ICONQUESTION|MB_RETRYCANCEL);
   	}while(flag != 2);
   	return (0);
   }
   ```

**Time：2021-12-31 9:57:00**

## The v2.4

1. 备份代码 跨年大更新！
2. (简称无更新——狗头保命😁)

**Time：2022-02-03 16:07:54**

## The v3.0

1. 首份公共测试文件发布🧨

2. 产生运行报告🧾

3. 灵活设置功能上线

   ```c++
   #define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
   #include <bits/stdc++.h>
   #include <windows.h>
   
   unsigned long long MAXN, cnt; // 最大号数 计数器
   unsigned short flag;     // 检验是否停止循环
   long long e;
   
   char empty;
   char num[4];
   
   using namespace std;
   int main() {
   	MessageBox(GetForegroundWindow(), "请在打开的文本文档中输入最大的号数", "温馨提示: 数字与数字之间隔一行", MB_OK);
   	system("setting.txt");
   
   	FILE *read;
   	read = fopen("setting.txt", "r");
   
   	fscanf(read, "%lld", &MAXN);
   
   
   	FILE *say;
   	say = fopen("本次运行抽中号码表.txt", "w");
   
   	fprintf(say, "本次运行抽中号码如下:\n");
   	system("本次运行抽中号码表.txt");
   
   	uniform_int_distribution<int> Romdom(1, MAXN);
   	default_random_engine Engine(time(NULL));
   	int tong[MAXN + 5] = {};
   	do
   	{
   		if(cnt == MAXN){
   			MessageBox(GetForegroundWindow(), "所有号数都抽完啦,请查看‘本次运行抽中号码表.txt’", "警告", MB_ICONWARNING);
   			fprintf(say, "所有号数都抽完啦,感谢您的使用!再会!");
   			exit(0);
   		}
   
   		e = Engine();
   		long long rom = Romdom(Engine);
   
   		if(tong[rom])
   			continue;
   
   		else if(tong[rom] == 0) tong[rom] = 1;
   
   		fprintf(say, "%lld \n", rom);
   
   		num[0] = '{';
   		num[3] = '}';
   
   		num[1] = rom / 10 + '0';
   		num[2] = rom % 10 + '0';
   
   		if(num[1] == '0'){
   			num[1] = num[2];
   			num[2] = '}';
   			num[3] = empty;
   		}
   
   		char TEXT[24] = "新鲜出炉的是…… ";
   		char OUTPUT[128];
   
   		strcpy(OUTPUT, strcat(TEXT, num));
   
   		flag = MessageBox(GetForegroundWindow(),OUTPUT,"[重试] 再抽一个  [取消] 退出程序",MB_ICONQUESTION|MB_RETRYCANCEL);
   		cnt++;
   	}while(flag != 2);
   
   	fprintf(say, "总计%lld人,感谢您的使用!再会!", cnt);
   
   	fclose(say);
   	fclose(read);
   	return 0;
   }
   ```

**Time：2022-02-15 17:43:37**