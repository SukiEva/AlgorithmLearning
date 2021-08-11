import os
import datetime

def get_dirs():
    dirs = []
    ignore_list = ['.git', '.vscode', 'data',
                   '.gitignore', 'README.py', '00数据结构', 'README.txt', 'README.md']
    for dirname in os.listdir():
        if dirname not in ignore_list:
            dirs.append(dirname)
    return dirs


def insert_txt(dirpath):
    with open("README.txt", "a", encoding='utf-8') as f:
        for root, dirs, files in os.walk(dirpath):
            dir_depth = len(root.split(os.path.sep))+1
            h = '#'*dir_depth + ' '
            if dir_depth>2:
                h2 = root[root.rfind('\\')+1:]
            else:
                h2 = root[1] + "、"+root[2:]
            lk = "https://github.com/SukiEva/AlgorithmLearning/tree/master/" + root.replace("\\", "/")
            f.write(h+"["+h2+"]("+lk+')\n')
            cnt = 1
            for file in files:
                if '.cpp' in file:
                    name = file[0:file.rfind('.cpp')]
                    path = root.replace("\\", "/")+'/'+file
                    link = r"https://github.com/SukiEva/AlgorithmLearning/blob/master/"+path
                    f.write(str(cnt)+". ["+name+"]("+link+")\n")
                    cnt += 1
                    # print(file)


def rename():
    if os.path.exists('README.md'):
        os.rename("README.md", "README.txt")
        nowtime = datetime.datetime.now().strftime(r'%Y-%m-%d %H:%M:%S')#现在
        with open("README.txt", "w", encoding='utf-8') as f:
            f.write(
                "# LeetCode\n" +
                "本仓库为个人刷题学习仓库，记录学习过程\n\n" +
                "> PS : 此README由程序自动生成，最后更新："+nowtime+'\n'
            )
    elif os.path.exists("README.txt"):
        os.rename("README.txt", "README.md")
    else:
        file = open('README.txt', 'w')
        file.close()


rename()
dir_list = get_dirs()
for dirname in dir_list:
    insert_txt(dirname)
rename()
print("README生成成功")
