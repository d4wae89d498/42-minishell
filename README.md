# 42-minishell
minishell project for 42 school

todo 

- [ ] cd 1 2 too many args

- [x] check erreur executable path 
- [x]--> code 126 si pas de droit
- [x] exit avec CTRL + D doit exit avec le dernier exit code
- [x] ctrl + d heredoc gnl  ==> si buffer vide et end of read - > terminate heredoc and fire warning
                            ==> si buffer pas vide, ne rien faire  (pas de saut de ligne)

- [ ] gerer les err code dans les signaux
- [ ] secure syscalls / better error management
- [ ] gerer le invalid write des quotes pas close



- [ ] cd -

- [ ] $_
- [ ] cd ~ + ds le env / echo / export

- [ ] cd .. dans un deleted folder

- [ ]
MINISHELL: export export="ls -al"
MINISHELL: $export