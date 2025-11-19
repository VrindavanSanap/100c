./_create_shared_library.sh
clang++ ./foo_usage/main.cpp \
	-I ./foo/include \
	-o foo_app \
	-L . -lfoo
