/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:24:59 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/28 15:04:13 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::TREE =
"                                        ..........................          \n\
                                              ...................            \n\
                                        .          .....                     \n\
                              *. -* + *+.**@%*+##     .         ..           \n\
                         = .# **.=*##**:@:*#@%# :-   .         ...           \n\
                        . @*  * +. ****@=#=-+**%                             \n\
                      .@.+=-.+@ + @#* +=#++%## +* =                          \n\
                          #%#=*.:#-*+:=+=+#*=+*+%#.                          \n\
                     .:*-@% *.*+*#+ #* *#***+*=#@                            \n\
                 -:=%-* :-#:.##+=##%#=*****=%**#= *                          \n\
               - *=-..  @.#*@*+*#*@#*##+*+#*###**=-+                         \n\
                --..*=:+ *%*++*+#%*##%####%%###@#@%:%                        \n\
             +#%*+*+#*+##:**%#*%#%####+%##%@#*%%#%%*# -                      \n\
            --**@%**:.+*+#%*##=%%#@%%%*##@##@**@+#%##%+                      \n\
          .##*@%#+@+@+++#+#*+*%@#*%%* %*@@*#@@%@ ##@###*+:=                  \n\
         :*%#%:%+ **-@.*+:*:=:%%+%##*+ @ *% @%@@#@#%%#**+**.                 \n\
      -+-=*@@@#++*@+#* =.-=*@%*+@@@#@#%%%@#%*##@##. :%#%##*%#                \n\
      -  .+#. @@%.=-*+**...*.*-:*#-=%*%+#@*##%%%@+#@ +  #@=#+#               \n\
             - %   %.-:.*@@=:#-.## **##%%@@@@@* *%= %%@@ #% @                \n\
           .-*=%+:=    .=%..==*- :@%+##.%@%@ #% @*=%#+ ##@                   \n\
             .          -  ..:#*#%@@%@+#  #:@@@%@# -#:*%##                   \n\
                      %.: -.=....@%#+@=+ **   @% @*. +@##.*                  \n\
                         @  ..#=@@@@@*.-       .+  * :*@%%                   \n\
                          -  :   %%@#  :                 #                   \n\
                                 :%%-                                        \n\
                                 ##%%                                        \n\
             .......:.:-=:-.--.*=.-.+#+=-%#+=++-+*.                          \n\
+.:.:..:..:..=-+*+...::..:-+=:=.-:.:=:+=*=:*-+.+-+-..-+=---+--*.**..++*=-+*=*\n\
.=*..::-**--=*#:=:+:--=--..-=**#+*==*%=.=%**=#.*+:.#+++#+#==--+=*++**+#==+-+*";

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery form", false, 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &source)
	: AForm(source) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source) {
	if (this != &source) {
		AForm::operator=(source);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::FileOpenFailException::FileOpenFailException()
	: _msg("Cannot open file") {}

const char *ShrubberyCreationForm::FileOpenFailException::what() const throw() {
	return (_msg.c_str());
}

void ShrubberyCreationForm::formAction() const {
	std::string	  filename = getTarget() + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file) {
		throw FileOpenFailException();
	}
	file << ShrubberyCreationForm::TREE;
	file.close();
}
