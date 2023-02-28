# 42-minishell

Minishell project for 42 school. The goal was to make an UNIX Shell that works like Bash.


TODO :

- [x] cd 1 2 too many args
- [x] secure syscalls / better error management
- [x] gerer le invalid write des quotes pas close
- [x] shell level
- [x] check erreur executable path 
- [x]--> code 126 si pas de droit
- [x] exit avec CTRL + D doit exit avec le dernier exit code
- [x] ctrl + d heredoc gnl  ==> si buffer vide et end of read - > terminate heredoc and fire warning
							==> si buffer pas vide, ne rien faire  (pas de saut de ligne)
- [x] gerer les err code dans les signaux

