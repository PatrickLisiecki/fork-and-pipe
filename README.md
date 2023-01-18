# Fork and Pipe
Assignment for CSC 332 - Operating Systems with Professor Zaid Al-Mashhadani

# About the Project
One of the philosophies behind Unix is the motto do one thing and do it well. In this
spirit, each shell command usually has a very specific purpose. More complicated
commands can be constructed by combining simpler commands in a pipeline such that
the output of one command becomes the input to another command. The standard shell
syntax for pipelines is to list multiple commands, separated by vertical bars | (the pipe
character).

<details>
           <summary>Example</summary>
           <p>
                Use fork(), one form of exec() functions, so that the first child will perform ls -F and
                pass the output to the second child using one direction pipe, so the second one can
                perform nl on the list of current directory contents. Later the second child process will
                print to the screen the result (see example below). The parent process must wait for its
                both children.
                <br>
                <br>
                In the below example the output from the ls -F command is piped to input of the nl command.
           </p>
</details>
