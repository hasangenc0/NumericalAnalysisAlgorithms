.PHONY : $(OutputFileName) runtest clear

CPP = g++
CPPFLAGS = -c
OVEPATH = src/EquationsInOneVariable/OneVariableFunction
BISECTIONPATH = src/EquationsInOneVariable/BisectionMethod
FIXEDPOINTPATH = src/EquationsInOneVariable/FixedPointMethod
NEWTONPATH = src/EquationsInOneVariable/NewtonRaphsonMethod
GTEST = ./lib/googletest/googletest/include
INC = -I ${NEWTONPATH} -I ${OVEPATH} -I ${BISECTIONPATH} -I ${FIXEDPOINTPATH} -I ${GTEST}
LIB = ${NEWTONPATH}/NewtonRaphsonMethod.cpp $(BISECTIONPATH)/BisectionMethod.cpp ${OVEPATH}/OneVariableFunction.cpp $(FIXEDPOINTPATH)/FixedPointMethod.cpp lib/googletest/googletest/libgtest.a lib/googletest/googletest/libgtest_main.a
OutputFileName = test.o
InputFileName = test/Test.cpp


$(OutputFileName):
	 @$(CPP) $(INC) -o ./bin/$(OutputFileName)  $(InputFileName) $(LIB)

runtest:
	 @./bin/$(OutputFileName)

clear:
	 @rm -f ./bin/$(OutputFileName)

test: $(OutputFileName) runtest clear
	@#intentionally left 1 tab
