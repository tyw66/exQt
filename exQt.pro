#--------------------------------------------
# @tyw66's Qt exercise project
#--------------------------------------------
TEMPLATE = subdirs
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

SUBDIRS += \
#        data_serialize \        #Qt序列化和反序列化
#        easy_notepad \          #简易文本编辑器
#        icon_edit \             #2017-07-21 ？？？
#        model_view  \           #2018-10-08 学习Qt项视图
#        ex_process\             #2019-04-06 学习Qt进程
#        financial_calculator\   #2019-04-29 复利计算器
#        ex_signalslot\          #2019-11-04 学习信号槽编译后的代码
#        thread_animation\       #2019-12-10 线程动画
#        delegate\               #2020-05-07 委托
#        funnyface\              #2020-05-25 滑稽表情
#        scrollbutton\           #2021-08-10 水平滚动按钮
#        data_sync \             #2021-09-07 界面数据同步（信号槽方案）
#        easy_skin \             #换皮肤
#        justforfun \            #2022-03-20 桌面小工具
#        ex_qmake \              #2022-04-07 学习QMake
#        language  \             #2022-04-07 学习Qt实时翻译
        ex_qsharedpointer \     #2022-04-10 Qt智能指针
#        ex_dll \                #2022-05-02 库链接库
#        test
#        LongTimeWork \
#        exThread \              #2022-06-27 学习Qt多线程的四种方法
#         study_example\          #2022-09-10 学习Qt自带demo
#         ex_graphicView \        #2022-09-13 学习图像视图框架
#         ex_grahicView2 \
#         ex_painter2D \          #2022-09-20 学习2D绘图:鼠标贪食蛇
#    ProcessWatcher \            #2022-10-06 多任务并行
#    AutoTest \
#    drawer \
 \#    PropertyAnimation
    ex_thread           #2022-12-01 Linux线程





