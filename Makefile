##
## Makefile for plazza in /home/le_l/Workspace/plazza
##
## Made by Victor Le
## Login   <le_l@epitech.net>
##
## Started on  Sun Apr 10 09:11:57 2016 Victor Le
## Last update Sat Apr 23 15:01:05 2016 Victor Le
##

RM		= rm -rf
MKDIR		= mkdir -p

CC		= g++

CXXFLAGS	+= -W -Wall -Wextra -Werror
CXXFLAGS	+= -I./includes -I./includes/Error -I./includes/Encrypt
CXXFLAGS	+= -std=gnu++11

NAME		= plazza

FILENAME	= main			\
		Plazza			\
		ArgParser		\
		Regex			\
		InputReader		\
		CmdParser		\
		Order			\
		SerialData		\
		PipeBase		\
		PipeIn			\
		PipeOut			\
		DuplexPipe		\
		Process			\
		SigpipeHandler		\
		Error/InvalidArgument	\
		Error/BadCmd		\
		Error/SerializeError	\
		Error/PipeError		\
		Error/Fork_error	\
		Error/Thread_error	\
		Error/FileError		\
		Error/LogicalError	\
		Error/SignalError	\
		encryption/CaesarCipher	\
		encryption/XorCipher	\
		encryption/Encryption	\
		encryption/NoEncryption	\
		encryption/AEncryption
SUBDIR		= Error			\
		encryption

SRCS_DIR	= srcs
SRCS_FILE	= $(addsuffix .cpp, $(FILENAME))
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

OBJS_DIR	= objs
OBJS_SUBDIR	= $(addprefix $(OBJS_DIR)/, $(SUBDIR))
OBJS_FILE	= $(addsuffix .o, $(FILENAME))
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS_FILE:.cpp=.o))

LDFLAGS		= -pthread


## Classic rules
all: subdir $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

## Generating object files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

## Generate necessary directories for object files
subdir: $(OBJS_SUBDIR)

$(OBJS_SUBDIR):
	$(MKDIR) $@

.PHONY: re fclean clean all subdir
