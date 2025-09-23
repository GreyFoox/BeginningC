import random
import os
def check_num(): # 使用random的choice实现验证码
    code_num = ""
    ran_num = []
    for i in range(10):
        ran_num.append(chr(ord("0")+i))
    for i in range(26):
        ran_num.append(chr(ord("a")+i))
        ran_num.append(chr(ord("A")+i))
    for i in range(4):
        code_num += random.choice(ran_num)

    print("验证码:{}".format(code_num))
    code_input = input("请输入验证码:")
    if code_num.upper() == code_input.upper(): # 一般验证码对大小写没要求
        print()
        return 1
    else:
        return 0

def find_all(): # 查询所有信息
    try:
        with open("score.csv") as f:
            lines = f.readlines()
            if lines == [] or len(lines) == 1: # 判断是否存在数据
                print("无学生信息")
                return
        d_score = {}
        with open("score.csv") as f:
            lines = f.readlines()
            for line in lines:
                if line == lines[0]:
                    title = lines[0].strip().split(",")
                    #{"":["","","","","",""]}
                else:
                    info = line.strip().split(",")
                    d_score[info[0]] = info[1:]
                    length = len(info[0])
        print("{1:^{0}}".format(length+6, title[0]), end="") # 这往下是仿照表格样子输出成绩单，不使用tabulate库
        for t in title[1:]:
            print("{:^6}".format(t), end="")
        print()
        for k,v in d_score.items():
            print("{1:^{0}}".format(length+8, k), end="")
            for t in v:
                if t == v[0]:
                    print("{:^6}".format(t), end="")
                else:
                    print("{:^8}".format(t), end="")
            print()
                
    except FileNotFoundError: # 判断文件是否存在
        print("无学生信息")

def find_by_ID(ID_input): # 查询指定信息
    try:
        with open("score.csv") as f:
            lines = f.readlines()
            if lines == []:
                print("无学生信息")
                return
            for line in lines: # 处理一下csv数据
                if line == lines[0]:
                    title = line.strip().split(",")
                ID = line.strip().split(",")[0]
                if ID == ID_input:
                    info = line.strip().split(",")
                    for d in range(len(info)):
                        if info[d]:
                            print("{}:{}".format(title[d], info[d]), end="   ")
    except FileNotFoundError:
        print("无学生信息")
 
def add(s): # 添加信息
    info = s.split()
    with open("score.csv", "a") as fo: # 添加直接在原文件后面加
        fo.write(",".join(info) + "\n")

def revise(revise_ID, revise_info): # 修改信息
    d_score = {}
    name, subject, score = revise_info.split() # 要修改的数据
    with open("score.csv") as f:
        lines = f.readlines()
        for line in lines:
            if line == lines[0]:
                title = lines[0].strip().split(",")
                #{"":["","","","","",""]}构思出的字典长这样
            else:
                info = line.strip().split(",")
                d_score[info[0]] = info[1:] # 只拿出分数的一部分
        idx = title.index(subject)
        info = d_score[revise_ID]
        info[0] = name
        info[idx-1] = score # 这一步部分是获取原科目的分数位置索引，直接改列表对应位置的数据
        d_score[revise_ID] = info
    with open("score.csv", "w") as fo:
        fo.write(",".join(title)+"\n")
        for k,v in d_score.items():
            fo.write("{},{}\n".format(k,",".join(v))) # 写入数据
        print("修改成功")
'''梳理一下思路，把全部信息拿出来，单独替换要修改的信息，然后再放进去，
这样如果是3.7版本以上，字典的物理地址不会变，数据顺序就不会变（ps:主要还是懒啊）'''

def delect(s): # 删除信息
    d_score = {}
    with open("score.csv") as f:
        lines = f.readlines()
        for line in lines:
            if line == lines[0]:
                title = lines[0].strip().split(",")
                #{"":["","","","","",""]}
            else:
                info = line.strip().split(",")
                d_score[info[0]] = info[1:]
        d_score.pop(s) # 跟上面差不多，全部拿出来，然后删一个放进去，因为这个思路比较简单
    with open("score.csv", "w") as fo:
        fo.write(",".join(title) + "\n")
        for k,v in d_score.items():
            fo.write("{},{}\n".format(k,",".join(v)))
        print("删除成功")

def rank():
    d_score = {}
    ls_info = []
    count = 0
    with open("score.csv") as f:
        lines = f.readlines()
        for line in lines:
            if line == lines[0]:
                title = lines[0].strip().split(",") + ["排名"]
                #{"":["","","","","",""]}
            else:
                info = line.strip().split(",")
                d_score[info[0]] = info[1:]
                length = len(info[0])
    lt_score = list(d_score.items())
    lt_score.sort(key=lambda x:sum(map(eval,x[1][1:])), reverse = True)
    title_str = "{1:^{0}}".format(length+6, title[0]) # 下面都是处理数据成一个有排名成绩单的列表
    info_str = ""
    for t in title[1:]:
        title_str += "{:^6}".format(t)
    ls_info.append(title_str)
    for k,v in lt_score:
        count += 1
        info_str = "{1:^{0}}".format(length+8, k)
        for t in v:
            if t == v[0]:
                info_str += "{:^6}".format(t)
            else:
                info_str += "{:^8}".format(t)
        info_str += "{:^8}".format(count)
        ls_info.append(info_str)
    return ls_info

def print_info_by_score(score_c, idx_c): # 这个跟rank函数思路类似，不过加了个分支判断，把不符合要求的数据去掉了
    d_score = {}
    ls_info = []
    count = 0
    score_c = eval(score_c)
    with open("score.csv") as f:
        lines = f.readlines()
        for line in lines:
            if line == lines[0]:
                title = lines[0].strip().split(",") + ["排名"]
                #{"":["","","","","",""]}
            else:
                info = line.strip().split(",")
                d_score[info[0]] = info[1:]
                length = len(info[0])
    lt_score = list(d_score.items())
    lt_score.sort(key=lambda x:sum(map(eval,x[1][1:])), reverse = True)
    title_str = "{1:^{0}}".format(length+6, title[0])
    info_str = ""
    for t in title[1:]:
        title_str += "{:^6}".format(t)
    ls_info.append(title_str)
    for k,v in lt_score:
        ls_score = list(map(eval,v[1:]))
        ave_score = sum(ls_score)/len(ls_score)
        count += 1
        if idx_c == "大于" and ave_score >= score_c:
            info_str = "{1:^{0}}".format(length+8, k)
            for t in v:
                if t == v[0]:
                    info_str += "{:^6}".format(t)
                else:
                    info_str += "{:^8}".format(t)
            info_str += "{:^8}".format(count)
            ls_info.append(info_str)
        if idx_c == "小于" and ave_score <= score_c:
            info_str = "{1:^{0}}".format(length+8, k)
            for t in v:
                if t == v[0]:
                    info_str += "{:^6}".format(t)
                else:
                    info_str += "{:^8}".format(t)
            info_str += "{:^8}".format(count)
            ls_info.append(info_str)
    print("\n".join(ls_info))

def print_info_by_rank(rank_c, idx_c): # 这个跟rank函数思路一致，不过加了个分支判断，把不符合要求的数据去掉了
    if idx_c == "大于":
        print("\n".join(eval("rank()[:{}]".format(eval(rank_c)+1))))
    elif idx_c == "小于":
        print("\n".join(eval("rank()[{}:]".format(eval(rank_c)))))

def main(): # 主函数
    if check_num():
        mode_d = "0" #查询模式默认"0"
        while True: # 主循环
            print('''请选择操作：
查询 添加 修改 删除 计算 退出''') # 设置可选择各种模式
            cho = input()
            print()
            if cho == "查询":
                mode_input = input('''请选择查询模式:
0:全部查询
1:按学号查询
目前查询方法为{}:'''.format(mode_d))
                if mode_input:
                    mode_d = mode_input #带记忆的模式
                if mode_d == "0":
                    find_all()
                elif mode_d == "1":
                    ID_input = input("请输入学生学号：")
                    find_by_ID(ID_input)
                    print()
            if cho == "添加":
                with open("score.csv", "a+") as f: # 使用追加写+读的模式，避免了w+直接删除源文件，同时又避免了r+没有源文件报错的问题
                    f.seek(0) # 指针放开头
                    lines = f.readlines()
                    if lines == []:
                        title = ("学号 姓名 " + input("请添加学科（空格分割）:")).split() # 添加学科，前面加两词作为标题
                        f.write(",".join(title) + "\n")
                with open("score.csv") as f:
                    lines = f.readlines()
                    title = " ".join(lines[0].strip().split(","))
                print("当前标题行为:\n{}".format(title))
                print("请输入要添加的数据，格式为“学号+姓名+各科目分数（空格分割，分数与学科一一对应）”") # 单一添加数据
                add_str = input("例如“2406911050 小明 90 84 80”:")
                add(add_str)
            if cho == "修改":
                revise_ID = input("请输入要修改信息的学生学号：") # 修改数据
                print("该学生目前信息为:")
                find_by_ID(revise_ID)
                print()
                print("请输入要修改成的学生信息，格式为姓名+科目+分数：")
                revise_info = input("例如“小明 数学 80”:")
                revise(revise_ID, revise_info)
            if cho == "删除":
                del_mode = input('''请选择删除模式:
0:按学号删除
1:全部删除
不选择默认为0:''') # 我认为这个不需要记忆模式，毕竟删除全部数据是少数情况
                if not del_mode:
                    print("请输入要删除的学生的学号")
                    del_str = input("例如“2406911050”:")
                    delect(del_str)
                elif del_mode == "1":
                    os.remove("score.csv") # os库删除文件，这样全部删除比较简单粗暴
                    print("已全部删除")
            if cho == "计算":
                cho = input("请选择计算操作“排名”，“条件输出”:")
                if cho == "排名":
                    print("\n".join(rank()))
                elif cho == "条件输出":
                    condition = input("请选择条件“按平均分数”“按排名”:")
                    if condition == "按平均分数":
                        score_c = input("请输入分数节点（例如80）:")
                        idx_c = input("输出大于或小于（大于/小于）:")
                        print_info_by_score(score_c, idx_c)
                    elif condition == "按排名":
                        rank_c = input("请输入排名节点(例如5):")
                        idx_c = input("输出大于或小于（大于/小于【包含节点】）:")
                        print_info_by_rank(rank_c, idx_c)
            if cho == "退出":
                return
            print()


if __name__ == "__main__": # 防止被调用直接运行主函数
    main()
