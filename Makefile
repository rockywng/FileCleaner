CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Wno-unused
EXEC = clean
OBJECTS = main.o indents.o newline.o includeguard.o filename.o readwrite.o clean.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
.PHONY: cleanup
cleanup:
	del ${OBJECTS} ${EXEC} ${DEPENDS}
