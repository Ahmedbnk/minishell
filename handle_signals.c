#include "minishell.h"

void	sigint_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

// steal have a problem here in the sigquit handler
// void disable_quit_echo(void)
// {
//     struct termios term;
//     tcgetattr(STDIN_FILENO, &term);
//     term.c_cc[VQUIT] = 0;
//     tcsetattr(STDIN_FILENO, TCSANOW, &term);
// }

void	handle_signals(void)
{
	struct sigaction sa;

	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);

	signal(SIGQUIT, SIG_IGN);
}