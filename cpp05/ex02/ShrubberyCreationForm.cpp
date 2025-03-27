/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:24:59 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/27 11:46:27 by lemercie         ###   ########.fr       */
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


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("Shrubbery form", false, 145, 137, target)
{
	std::cout << "Shr constructor with nameattribute" << target << std::endl;
}

ShrubberyCreationForm::FileOpenFailException::FileOpenFailException()
	: _msg("Cannot open file") {}

const char *ShrubberyCreationForm::FileOpenFailException::what() const throw() {
	return (_msg.c_str());
}

void	ShrubberyCreationForm::formAction() const {
	std::string	filename = getTarget() + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file) {
		throw FileOpenFailException();
	}
	file << ShrubberyCreationForm::TREE;
	file.close();
}
