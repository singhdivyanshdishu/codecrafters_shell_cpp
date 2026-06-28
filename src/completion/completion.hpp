#pragma once

char *builtinGenerator(const char *text, int state);

char **builtinCompletion(const char *text, int start, int end);

void initializeCompletion();
