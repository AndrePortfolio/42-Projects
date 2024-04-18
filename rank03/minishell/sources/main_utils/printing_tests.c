/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:28:27 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 13:31:32 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* void	print_tokens(t_tokens *head)
{
	t_tokens	*current = head;
	int			index = 1;

	while (current != NULL)
	{
		fprintf(stderr, "+----------------------------------+\n");
		fprintf(stderr, "| Node %d                           |\n", index);
		fprintf(stderr, "+----------------------------------+\n");
		fprintf(stderr, "| Value: %-25s |\n", current->value);
		fprintf(stderr, "| Type: %-26d |\n", current->type);
		printf("| Space: %-26d |\n", current->space);

		if (current->previous != NULL)
			printf("| Previous: Node %-4d (%-10s)|\n", index - 1,
            current->previous->value);
		else
			printf("| Previous: %-24s|\n", "NULL");

		if (current->next != NULL)
			printf("| Next: Node %-8d (%-10s)|\n", index + 1,
			current->next->value);
		else
			printf("| Next: %-28s|\n", "NULL");
		printf("+----------------------------------+\n\n");
		current = current->next;
		index++;
	}
}

static void print_indent(int level)
{
    for (int i = 0; i < level * 4; i++) {
        printf(" ");
    }
}

void print_builtin_name(int (*builtin)(t_shell *, struct s_tree_node *tree)) {
    if (builtin == NULL)
        return;

    // Compare the function pointer against the builtin array
    static void	*builtins[7][2] =
	{
		{"echo", mini_echo},
		{"cd", mini_cd},
		{"pwd", mini_pwd},
		{"export", mini_export},
		{"unset", mini_unset},
		{"env", mini_env},
		{"exit", mini_exit}
	};
    int num_builtins = sizeof(builtins) / sizeof(builtins[0]);

    for (int i = 0; i < num_builtins; i++) {
        if (builtins[i][1] == (void *)builtin) {
            printf("Builtin function: %s\n", (char *)builtins[i][0]);
            return;
        }
    }

    // Print (null) if no match found (shouldn't happen in your case)
    printf("Builtin function: (null)\n");
}

void print_tree(t_tree_node *root, int level)
{
    if (root == NULL) {
        return;
    }

    print_indent(level);
    printf("Node Type: %d\n", root->type);

    if (root->type == CMD) {
        print_indent(level);
        printf("Command: %s\n", root->cmd);
    }

    // Print builtin
    if (root->builtin != NULL)
    {
        print_indent(level);
        print_builtin_name(root->builtin);
    }

    // Print arguments list
    t_args *args = root->args;
    print_indent(level);
    printf("Arguments:\n");
    if (args == NULL)
        printf("(null)\n");
    while (args != NULL) {
        print_indent(level);
        printf("%s\n", args->arg);
        args = args->next;
    }

    // Print redirection list
    t_redir_list *redir = root->redir_list;
    print_indent(level);
    printf("Redirection List:\n");
    if (redir == NULL)
        printf("(null)\n");
    while (redir != NULL) {
        print_indent(level);
        printf("Type: %d, File: %s\n", redir->type, redir->file);
        redir = redir->next;
    }

    print_indent(level);
    printf("Left subtree:\n");
    print_tree(root->left, level + 1);

    print_indent(level);
    printf("Right subtree:\n");
    print_tree(root->right, level + 1);
	printf("\n");
}

void    print_envp(t_shell *shell)
{
    char **envp;

    envp = shell->envp;
    int i = 0;
    while (envp[i])
    {
        printf("%s\n", envp[i]);
        i++;
    }
} */
