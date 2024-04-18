/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:55:07 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 15:44:38 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <errno.h>

# define SINGLE_TOKENS "<>|"
# define WHITESPACE " \t\n\v\f\r"
# define WHITESPACE_DOLLAR " \t\n\v\f\r$"
# define LETTERS_DIGITS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcd\
efghijklmnopqrstuvwxyz0123456789_"
# define WHITESPACE_DOLLAR_SINGLE " \t\n\v\f\r$\'"
# define WHITESPACE_QUOTES " \t\n\v\f\r\'\""
# define WHITESPACE_Q_D " \t\n\v\f\r\'\"$?<>|"
# define WHITESPACE_Q_D_N " \t\n\v\f\r\'\"$<>|"
# define QUOTE_DELIMITER "$\""
# define TRUE 1
# define FALSE 0
# define WRITE_END 1
# define READ_END 0
# define INPUT 0

# define RED "\x1b[31;1m"
# define GREEN "\x1b[32;1m"
# define BLUE "\x1b[34;1m"
# define CYAN "\x1b[36;1m"
# define RESET "\x1b[0m"

# define MAIN 42
# define MAIN_PROMPT 43
# define CHILD 44
# define IGN 45
# define HERE 46

/*-------------------------------structs----------------------------*/
/*------------------------------------------------------------------*/

typedef enum e_tree_type
{
	PHANTOM,
	PIPE_TREE,
	CMD,
	BUILTIN
}	t_tree_type;

typedef enum e_token_type
{
	PIPE,
	RE_INPUT,
	RE_OUTPUT,
	APPEND,
	HEREDOC,
	WORD,
	ENV_VAR
}	t_token_type;

typedef struct s_args
{
	int					space;
	char				*arg;
	struct s_args		*next;
}						t_args;

typedef struct s_redir_list
{
	t_token_type		type;
	char				*file;
	struct s_redir_list	*next;
}						t_redir_list;

typedef struct s_tokens
{
	t_token_type		type;
	int					space;
	char				*value;
	struct s_tokens		*previous;
	struct s_tokens		*next;
}						t_tokens;

typedef struct s_envps
{
	char				*pwd;
	char				*oldpwd;
	char				*home;
	int					pwd_index;
	int					oldpwd_index;
}						t_envps;

typedef struct s_shell
{
	char				**envp;
	char				*pwd;
	char				*oldpwd;
	pid_t				*id;
	int					*id_exec;
	int					**fd;
	char				*line;
	int					infile;
	int					outfile;
	bool				here_doc;
	bool				reseted;
	char				*error_file;
	int					fds_heredoc[2];
	int					pipe_nbr;
	int					status;
	int					builtins;
	int					std_fds[2];
	struct s_tree_node	*tree;
	t_tokens			*tokens;
	int					i;
}						t_shell;

typedef struct s_tree_node
{
	t_tree_type			type;
	char				*cmd;
	int					(*builtin)(t_shell *s, struct s_tree_node *cmd_node);
	struct s_args		*args;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
	struct s_redir_list	*redir_list;
}						t_tree_node;

typedef struct s_info
{
	t_shell				*info;
}						t_info;

/*---------------------------------minishell---------------------------------*/
/*---------------------------------------------------------------------------*/
void		init_shell(t_shell *shell, char **envp);
void		copy_envp(t_shell *shell, char **envp);
t_info		exit_info(t_shell *shell);
void		init_missing_env(t_shell *shell);
void		get_prompt(t_shell *shell);
void		loop(t_shell *shell);
void		get_status(t_shell *shell, int status);
void		wait_pids(t_shell *shell);
void		increase_shlvl(t_shell *s);
void		add_missing_env(t_shell *s);
void		close_wait_reset(t_shell *shell);
void		prepare_tokens(t_shell *shell);

/*---------------------------------parsing-----------------------------------*/
/*---------------------------------------------------------------------------*/
t_tree_node	*parse_commandline(t_tokens *tokens_start, t_shell *shell);
t_tree_node	*add_ast_node(void);
void		add_redir_list(t_redir_list **head, t_token_type type, char *file);
void		add_arg(t_args **args, t_tokens *current);
t_tree_node	*parse_cmd(t_tokens *t_start, t_tokens *t_end, t_shell *shell);
void		count_pipes(t_shell *shell);
bool		check_syntax_errors(char *line);
bool		check_quotation_marks(char *line);
bool		check_pipes(char *line);
void		clean_up(t_shell *shell, bool print_msg);
bool		check_tokens(t_tokens *tokens);
void		ft_cmd_node(t_tree_node *cmd_node, t_tokens *current, t_shell *s);

/*---------------------------------tokenization------------------------------*/
/*---------------------------------------------------------------------------*/
t_tokens	*tokenize(t_shell *shell);
t_tokens	*get_tokens(char *line);
char		*handle_single_quotes(char *start, t_tokens *token);
char		*handle_double_quotes(char *start, t_tokens *token);
char		*token_word(char *start, t_tokens *token, char *delimiter);
char		*single_token(char *start, t_tokens *token);
char		*token_envp(char *start, t_tokens *token);
void		free_tokens(t_tokens *head);
t_tokens	*add_node_back(t_tokens *previous);
t_tokens	*token_init(void);
char		*ft_strdup_delimiter_char(const char *s, char delimiter);
char		*ft_strdup_delimiter_string(const char *s, char *delimiter);
char		*ft_strdup_while_string(const char *s, char *delimiter);
char		*skip_whitespace(char *line);
int			args_len(t_args *args);
char		*token_dollar(char *start, t_tokens *token);
void		del_token(t_tokens **head, t_tokens *node);
void		remove_spaces(t_tokens **tokens);
void		remove_empty_tokens(t_tokens **tokens);
char		*trim_line(char *line, char *set);
void		pre_parse_tokens(t_tokens *tokens);

/*---------------------------------expansion---------------------------------*/
/*---------------------------------------------------------------------------*/
void		expand(t_shell *shell);
char		*get_env(t_shell *shell, char *str);
char		*find_env(char *str);
char		*ft_strdup_until(char *s);
void		free_strs(char *s1, char *s2, char *s3);
char		*find_and_replace(t_shell *shell, char *org_str);

/*---------------------------------builtins----------------------------------*/
/*---------------------------------------------------------------------------*/
int			(*builtin_arr(char *str))(t_shell *s, struct s_tree_node *tree);
int			mini_cd(t_shell *shell, t_tree_node *tree);
int			mini_echo(t_shell *shell, t_tree_node *cmd_node);
int			mini_export(t_shell *shell, t_tree_node *tree);
int			mini_env(t_shell *shell, t_tree_node *tree);
int			mini_exit(t_shell *shell, t_tree_node *tree);
int			mini_pwd(t_shell *shell, t_tree_node *tree);
int			mini_unset(t_shell *shell, t_tree_node *tree);
int			char_arr_len(char **arr);
int			export_error(char *c);
int			check_valid_identifier(char c);
void		get_env_vars(t_shell *s);
void		add_env(t_shell *s, char *var);
void		print_env(char **env);
char		*find_path_ret(char *str, t_shell *s);
void		change_path(t_shell *shell);
int			is_inenvp(char **env, char *var);
void		check_append(char *var, int *flag_append);
int			check_var(char *var);
void		add_value(t_args *current, int flag_append, char *var, t_shell *s);
char		**copy_env(char **envp);
void		sort_env(char **envp);
void		append_env(char **s, char *var, char *value);

/*--------------------------------execution----------------------------------*/
/*---------------------------------------------------------------------------*/
void		execute(t_shell *shell);
void		prepare_to_execute(t_shell *shell);
void		alloc_pipes(t_shell *shell);
void		exec_pipe(t_shell *s, t_tree_node *l_nd, t_tree_node *r_nd, int i);
void		start_execution(t_shell *s, t_tree_node *node, int i, bool l_cmd);
void		execute_command(t_shell *shell, t_tree_node *node);
void		redirect_input_output(t_shell *shell, int i, bool last_cmd);
char		**get_full_cmd(t_tree_node *node);
char		*check_path(char *cmd, char **envp, int *flag);
char		*get_path(char *cmd, char **envp);
void		get_path_index(char **envp, int *index);
void		free_and_close(int fd, char **paths, char *path, char *path_cmd);
void		invalid_path(char **full_command, t_shell *shell, char *command);
bool		open_files(t_shell *shell, t_redir_list *file);
bool		open_infile(t_shell *s, t_redir_list *curr, int *f_in, int *f_out);
void		open_outfil(t_shell *s, t_redir_list *curr, int *f_in, int *f_out);
bool		init_heredoc(char *limiter, t_shell *shell, int f_in, int f_out);
void		exec_child_here(t_shell *s, char *limit, char *line, int pipe_nbr);
void		reset_heredoc_fds(t_shell *shell);
bool		check_access(t_shell *shell, int flag_in, int flag_out);
void		exec_child_here(t_shell *s, char *limit, char *line, int pipe_nbr);
void		executable(t_shell *shell, char *path, char **full_cmd, char *cmd);
void		exec(t_shell *shell, char *path, char **cmd);
void		execute_child(t_shell *shell, t_tree_node *node, int i);

/*---------------------------------freeing-----------------------------------*/
/*---------------------------------------------------------------------------*/
void		free_all(t_shell *shell);
void		free_redir_list(t_redir_list *redir_list);
void		free_args(t_args *args);
void		free_tree(t_tree_node *node);
void		free_tokens(t_tokens *head);

/*-----------------------------------reset-----------------------------------*/
/*---------------------------------------------------------------------------*/
void		reset(t_shell *shell);
void		reset_fds(t_shell *shell);
void		close_all_fds(t_shell *shell, bool in_out);

/*----------------------------------signals----------------------------------*/
/*---------------------------------------------------------------------------*/
void		signals(int n);
void		sigint_handler(int sig);

/*-------------------------------close program-------------------------------*/
/*---------------------------------------------------------------------------*/
void		error_message(char *message, char *cmd);
void		exit_error_message(char *message, int exit_code);
void		child_error_msg(t_shell *shell, char *msg, char *cmd, int code);

/*---------------------------------testing-----------------------------------*/
/*---------------------------------------------------------------------------*/
void		print_tokens(t_tokens *head);
void		print_tree(t_tree_node *root, int level);
void		print_envp(t_shell *shell);

#endif
