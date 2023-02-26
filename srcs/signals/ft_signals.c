#include "../../minishell.h"

void	ft_set_parent_interactive(void)
{
	signal(SIGINT, &ft_parent_interactive_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_set_parent_active(void)
{
	signal(SIGINT, &ft_parent_active_sigint);
	signal(SIGQUIT, &ft_parent_active_sigquit);
}

	//signal(SIGINT, &ft_parent_active_sigint);
	//signal(SIGQUIT, SIG_DFL);
void	ft_set_parent_heredoc(void)
{
	struct sigaction	response;

	sigemptyset(&response.sa_mask);
	response.sa_flags = SA_SIGINFO;
	response.sa_handler = &ft_parent_active_sigint;
	sigaction(SIGINT, &response, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_set_child_active(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
