上传代码
git add README.md // git add -u
git commit -m "first commit"
git push origin master
t213249544

下载仓库
1.SSH的方式
	$ git clone git@github.com:Tomosom/cplus_projects.git

首先在本地创建ssh key；
	$ ssh-keygen -t rsa -C "your_email@youremail.com"
	$ ssh-keygen -t rsa -C "764575907@qq.com"
后面的your_email@youremail.com改为你在github上注册的邮箱，之后会要求确认路径和输入密码，我们这使用默认的一路回车就行。成功的话会在~/下生成.ssh文件夹，进去，打开id_rsa.pub，复制里面的key。

回到github上，进入 Account Settings（账户配置），左边选择SSH Keys，Add SSH Key,title随便填，粘贴在你电脑上生成的key。

github-account
为了验证是否成功，在git bash下输入：
	$ ssh -T git@github.com
如果是第一次的会提示是否continue，输入yes就会看到：You've successfully authenticated, but GitHub does not provide shell access 。这就表示已成功连上github。

接下来我们要做的就是把本地仓库传到github上去，在此之前还需要设置username和email，因为github每次commit都会记录他们。
	$ git config --global user.name "your name"
	$ git config --global user.name "Tomosom"
	$ git config --global user.email "your_email@youremail.com"
	$ git config --global user.email "764575907@qq.com"


2.HTTPS的方式
	$ git clone https://github.com/Tomosom/cplus_projects.git


from net:
…or create a new repository on the command line
echo "# cplus_projects" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin git@github.com:Tomosom/cplus_projects.git
git push -u origin master

…or push an existing repository from the command line
git remote add origin git@github.com:Tomosom/cplus_projects.git
git push -u origin master

给Ubuntu下的Git添加颜色
	$ git config --global color.status auto
	$ git config --global color.diff auto
	$ git config --global color.branch auto
	$ git config --global color.interactive auto

无法连接github网站解决方法:
进入windows下路径为：C:\Windows\System32\drivers\etc\hosts
在hosts文件中加入下列IP，保存即可生效
#github
192.30.253.113 github.com
192.30.253.113 github.com
192.30.253.118 gist.github.com
192.30.253.119 gist.github.com
Linux下路径：/etc/hosts

test
