# qian — 签

一个具有图形化界面（XD依赖于WinAPI）的抽签项目，操作简单，界面人性化，静态编译后大小仅为3.2mb，单文件，对seewo一体机有较好适配。

**用于班级布置，参加福州市里科创比赛*

**状态：烂尾*

## 设计思路

图形化设计，利用`uniform_int_distribution`函数生成真随机数（“Windows下不可以生成真随机数”与WInAPI冲突实际使用为伪随机数），依靠梅森旋转算法生成定范围伪随机数，产生结果在程序目录下，要求可以根据用户使用设置相关数据。

## 弊端

经在班级测试趋向边界两端，结果与系统时间挂钩，强度较弱等

## 编译

推荐使用**Mingw**，如果非研究用推荐`-mwindows`

```bash
g++ "main.cpp" -o "Random.exe" -Wall -g -fexec-charset=GBK -std=c++11 -statisuan
```

##鸣谢

在此鸣谢：

​	**FengJingjing老师** 在测试阶段提供建议

​	**Tabclas** 为图形化方案带来新鲜的血液 

​	以及一直在背后支持的**父母**与将其公布于众的**指导老师LanXiaoyun**
