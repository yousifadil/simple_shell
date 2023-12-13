
/**
 * show_prompt - prints prompt text
 */

void show_prompt(void)
{
	const char prompt[] = "$ ";

	write(1, prompt, sizeof(prompt) - 1);
}
