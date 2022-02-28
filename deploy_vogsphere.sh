# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy_vogsphere.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:56:45 by cchen             #+#    #+#              #
#    Updated: 2022/02/02 14:25:33 by leotran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This shell file will be executed in the github actions envrionment when you push.
# Below is an example based on the libft project folder requirements. 

# $REPO_NAME will be replaced by the name of your Github repository on runtime
# intra-uuid-* is the name of the target repository that is created when it gets cloned,
# note that it ends with the wildcard (*) since the repo ID is renewed each time you fail.
# the intra-uuid-* folder is essentially the root of the vogsphere repository.

# Here you will write all of the logic of how to want to move your work from your
# Github repository ($REPO_NAME) to the vogsphere repository (intra-uuid-*)

# This shell script expects to be executed from the parent directory to the repositories

VOGSPHERE=$(ls | sed -n '/intra-uuid/p')

rm -rf ./${VOGSPHERE}/*

# Usage: cp ./$REPO_NAME/<folder>/<file_name> ./${VOGSPHERE}
cp ./$REPO_NAME/misc/author ./${VOGSPHERE}
