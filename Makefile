.PHONY : $(OutputFileName) runtest clear

CPP = g++
CPPFLAGS = -c
OVEPATH = src/EquationsInOneVariable/OneVariableEquation
BISECTIONPATH = src/EquationsInOneVariable/BisectionMethod
GTEST = ./lib/googletest/googletest/include
INC = -I ${OVEPATH} -I ${BISECTIONPATH} -I ${GTEST}
LIB = lib/googletest/googletest/libgtest.a lib/googletest/googletest/libgtest_main.a
OutputFileName = test.o
InputFileName = test/Test.cpp


$(OutputFileName):
	$(CPP) $(INC) -o ./bin/$(OutputFileName)  $(InputFileName) $(LIB)

runtest:
	./bin/$(OutputFileName)

clear:
	rm -f ./bin/$(OutputFileName)

test: $(OutputFileName) runtest clear
	