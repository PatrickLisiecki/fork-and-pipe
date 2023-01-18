# Fork and Pipe
Assignment for CSC 332 - Operating Systems with Professor Zaid Al-Mashhadani

# About the Project
* One of the philosophies behind Unix is the motto do one thing and do it well. In this
spirit, each shell command usually has a very specific purpose. More complicated
commands can be constructed by combining simpler commands in a pipeline such that
the output of one command becomes the input to another command. The standard shell
syntax for pipelines is to list multiple commands, separated by vertical bars | (the pipe
character).
* Use fork(), one form of exec() functions, so that the first child will perform ls -F and
pass the output to the second child using one direction pipe, so the second one can
perform nl on the list of current directory contents. Later the second child process will
print to the screen the result (see example below). The parent process must wait for its
both children.
* In the below example the output from the ls -F command is piped to input of the nl command.

<p align="center">
           <img 
                      src="https://user-images.githubusercontent.com/96704934/213078106-89c46552-bc52-4c67-915f-65b0c1819e70.PNG"
                      alt="Example"
                      title="Example Output"
           />
</p>

# Output in the Terminal
<p align="left">
           <img 
                      src="https://user-images.githubusercontent.com/96704934/213081217-65ff3d92-a35b-41e9-b2bb-008452a7d5f3.PNG"
                      alt="Output"
                      title="Output"
           />
</p>
