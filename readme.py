import os


def get_dirs():
    dirs = []
    ignore_list = ['.git', '.vscode', 'data',
                   '.gitignore', 'readme.py', '00数据结构', 'README.txt', 'README.md']
    for dirname in os.listdir():
        if dirname not in ignore_list:
            dirs.append(dirname)
    return dirs


def insert_txt(dirpath):
    with open("README.txt", "a", encoding='utf-8') as f:
        for root, dirs, files in os.walk(dirpath):
            dir_depth = len(root.split(os.path.sep))+1
            h = '#'*dir_depth + ' '
            f.write(h+root+'\n')
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
        with open("README.txt", "w", encoding='utf-8') as f:
            f.write(
                "# 前言\n" +
                "本仓库为个人刷题学习仓库，记录学习过程\n\n" +
                "PS : 此README由程序自动生成\n"
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
