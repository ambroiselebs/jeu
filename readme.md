# SETUP

## Getting stuff up and running

### MACOS
In the Makefile make sur that the `%.o: %.c` rule is using `INCLUDES_MAC` variable. <br />
Also ensure that `run` rule is using `mac` rule as dependencie

### LINUX/WINDOWS
In the Makefile make sur that the `%.o: %.c` rule is using `INCLUDES_LINUX` variable. <br />
Also ensure that `run` rule is using `linux` rule as dependecie

## Configuring the editor

# VSCODE
On vscode you have to add this path to your includePath setting
```
"${workspaceFolder}/mlx_mac",
"${workspaceFolder}/mlx_linux"
```
