#include "completion.hpp"

#include <cstring>
#include <cstdlib>
#include <string.h>

#include <readline/readline.h>

static const char *builtins[] =
{
    "echo",
    "exit",
    nullptr
};

char *builtinGenerator(const char *text, int state)
{
    static int index;

    if (state == 0)
    {
        index = 0;
    }

    size_t textLength = std::strlen(text);

    while (builtins[index] != nullptr)
    {
        const char *candidate = builtins[index++];

        if (std::strncmp(candidate, text, textLength) == 0)
        {
            // Readline frees the returned string.
            return ::strdup(candidate);
        }
    }

    return nullptr;
}

char **builtinCompletion(const char *text, int start, int end)
{
    (void)end;

    // Only perform completion for the command name.
    if (start != 0)
    {
        return nullptr;
    }

    return rl_completion_matches(text, builtinGenerator);
}

void initializeCompletion()
{
    // Register our completion callback with Readline.
    rl_attempted_completion_function = builtinCompletion;

    // Append a space after a unique completion.
    rl_completion_append_character = ' ';
}
