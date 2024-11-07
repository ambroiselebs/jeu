# SETUP

### MACOS
In the Makefile make sur that the `%.o: %.c` rule is using `INCLUDES_MAC` variable
Also ensure that `run` rule is using `mac` rule as dependecie

### LINUX/WINDOWS
In the Makefile make sur that the `%.o: %.c` rule is using `INCLUDES_LINUX` variable
Also ensure that `run` rule is using `linux` rule as dependecie
