Diary.txt文件中具体储存了一直以来的日记内容，而本次project的4个函数分别构成了4个不同的cpp文件。
此外还有一个Diary_functions.h文件声明了Diary 类的定义以及它所包含的各种函数以及其他的一些全局函数，这些函数的具体实现则在Diary_functions.cpp文件中实现。
4个函数包括：pdadd,pdlist,pdshow,pdremove.要测试其中一个函数，应该执行以下步骤（以pdadd函数为例）:
(1) g++ -c pdadd.cpp           //编译本函数的源文件，生成.o文件
(2) g++ -c Diary_functions.cpp           //编译类函数的源文件，生成.o文件
(3) g++ pdadd.o Diary_functions.o -o pdadd           //将已经生成的.o文件进行链接，生成名为pdadd的exe可执行文件。
(4) .\pdadd.exe             //运行可执行文件                             

几个函数的exe文件具体执行如下：
(1)pdadd.exe文件被执行后，出现提示语"Enter TimeStamp:",则输入本次写入日记的日期，按回车键结束；
出现提示语"Enter diary content:"，则开始写入本次日记的内容。若想结束本次日记的记录，则换行并输入.并按回车键，则本次日记记录结束。
(2)特别地，当在测试pdlist函数时，由于本函数可能带日期限制也可能不带，如果不需要带日期参数则按上述4个步骤执行即可；
如果自带参数则修改第(4)步为： .\pdlist.exe 2024 4 10 2024 4 30, 具体含义是：查询在2024年4月10日到2024年4月30日之间写下的所有日记。
(3)pdshow.exe文件被执行后，出现提示语"Please enter the date of diary you want to query",则输入想要查询日记的日期，按回车键结束；
出现提示语"Your diary:"，显示相应日期的日记内容。
(4)pdremove.exe文件被执行后，出现提示语"Please enter the date of diary you want to remove",则输入想要删除日记的日期，按回车键结束；若删除成功，函数返回0；否则返回-1；