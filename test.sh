#! /bin/zsh

RED="\e[31m"
GREEN="\e[32m"
MAGENTA="\e[95m"
CYAN="\e[96m"
ENDCOLOR="\e[0m"
BOLDGREEN="\e[1;${GREEN}m"
BOLDRED="\e[1;${RED}m"



echo -e "                           MANDATORY PART"
echo -e "                           -------1-------"
echo -e "                            ${GREEN}everyting OK${ENDCOLOR}"
echo -e "                            touch file1" && touch file1
echo -e "                   echo 'echo "hello, darling!" > file1'" && echo "hello, darling!" > file1
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' 'cat' 'cat' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' 'cat' 'cat' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 cat | cat > file2 && cat file2${ENDCOLOR}" && < file1 cat | cat > file2 && cat file2
echo -e "                           -------2-------"
echo -e "                      ${RED}INPUT FILE DOES NOT EXIST${ENDCOLOR}"
echo -e "                            unlink file1" && unlink file1
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' 'cat' 'cat' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' 'cat' 'cat' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 cat | cat >file2 && cat file2${ENDCOLOR}" && < file1 cat | cat >file2 && cat file2
echo -e "                           -------3-------"
echo -e "                           ${RED}NO SUCH COMMAND${ENDCOLOR}"
echo -e "                            touch file1" && touch file1
echo -e "                   echo 'echo "      here we go again..." > file1'" && echo "                          here we go again..." > file1
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' 'LOL' 'cat' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' 'LOL' 'cat' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 LOL | cat >file2 && cat file2${ENDCOLOR}" && < file1 LOL | cat >file2 && cat file2
echo -e "                           -------4-------"
echo -e "                      ${RED}OUTPUT FILE DOES NOT EXIST${ENDCOLOR}"
echo -e "                            unlink file2" && unlink file2
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' 'cat' 'cat' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' 'cat' 'cat' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 cat | cat > file2 && cat file2${ENDCOLOR}" && < file1 cat | cat >file2 && cat file2
echo -e "                           -------5-------"
echo -e "                      ${RED}RIGHTS TO FILE ARE PUT TO 000${ENDCOLOR}"
echo -e "                            chmod 000 file2" && chmod 000 file2
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' 'cat' 'cat' 'file2' ; cat file2${ENDCOLOR}" && ./pipex 'file1' 'cat' 'cat' 'file2' ; cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 cat | cat > file2 ; cat file2${ENDCOLOR}" && < file1 cat | cat >file2 ; cat file2
echo -e "                           -------6-------"
echo -e "                      ${GREEN}EXAMPLE OF OTHER COMMAND${ENDCOLOR}"
echo -e "                          chmod 777 file2" && chmod 777 file2
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' 'cat' 'wc -w' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' 'cat' 'wc -w' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 cat | wc -w > file2 && cat file2${ENDCOLOR}" && < file1 cat | wc -w >file2 && cat file2
echo -e "                           -------7-------"
echo -e "                      ${GREEN}BINARY ABSOLUTE PATH${ENDCOLOR}"
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' '/bin/cat' 'wc -w' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' '/bin/cat' 'wc -w' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 /bin/cat | wc -w > file2 && cat file2${ENDCOLOR}" && < file1 /bin/cat | wc -w >file2 && cat file2
echo -e "                           -------8-------"
echo -e "                      ${GREEN}FILE RELATIVE PATH${ENDCOLOR}"
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' './file2' 'wc -w' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' './file2' 'wc -w' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 ./file2 | wc -w > file2 && cat file2${ENDCOLOR}" && < file1 ./file2 | wc -w >file2 && cat file2
echo -e "                           -------8-------"
echo -e "                              ${GREEN}NO ARGS${ENDCOLOR}"
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex${ENDCOLOR}" && ./pipex
echo -e "                             BONUS PART"
echo -e "                           -------1-------"
echo -e "                            ${GREEN}(^・ω・^ )${ENDCOLOR}"
echo -e "                   echo "echo 'Do you still follow me? Hope, yes...' > file1"" && echo "Do you still follow me? Hope, yes..." > file1
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' 'cat' 'cat' 'cat' 'cat' 'cat' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' 'cat' 'cat' 'cat' 'cat' 'cat' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 cat | cat | cat | cat | cat > file2 && cat file2${ENDCOLOR}" && < file1 cat | cat | cat | cat | cat > file2 && cat file2
echo -e "                           -------2-------"
echo -e "                      ${GREEN}LET'S FIND ALL LINES WITH E${ENDCOLOR}"
echo -e "                   echo "echo 'Do you still follow me? Hope, yes...' > file1"" && echo "Do you still follow me? Hope, yes..." > file1
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' 'cat' 'cat' 'cat' 'cat' 'grep e -c' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' 'cat' 'cat' 'cat' 'cat' 'grep e -c' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 cat | cat | cat | cat | grep e -c > file2 && cat file2${ENDCOLOR}" && < file1 cat | cat | cat | cat | grep e -c > file2 && cat file2
echo -e "                           -------3-------"
echo -e "                            ${RED}GREP ERROR${ENDCOLOR}"
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'file1' 'cat' 'cat' 'cat' 'cat' 'grep' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'file1' 'cat' 'cat' 'cat' 'cat' 'grep' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}< file1 cat | cat | cat | cat | grep > file2 && cat file2${ENDCOLOR}" && < file1 cat | cat | cat | cat | grep > file2 && cat file2
echo -e "                           -------4-------"
echo -e "                             ${GREEN}HERE_DOC${ENDCOLOR}"
echo -e "                            ${CYAN}PIPEX OUTPUT${ENDCOLOR}"
echo -e "             ${MAGENTA}./pipex 'here_doc' '1' 'cat' 'cat' 'cat' 'file2' && cat file2${ENDCOLOR}" && ./pipex 'here_doc' '1' 'cat' 'cat' 'cat' 'file2' && cat file2
echo -e "                            ${CYAN}ZSH OUTPUT${ENDCOLOR}"
echo -e "               ${MAGENTA}cat << 1 | cat | cat | cat >> file2 && cat file2${ENDCOLOR}" &&  cat << 1 | cat | cat | cat >> file2 && cat file2






