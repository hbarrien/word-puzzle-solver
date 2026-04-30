##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Word_Puzzle_Solver
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/hpbar/Workspaces/HackerRank
ProjectPath            :=C:/Users/hpbar/Workspaces/HackerRank/Word_Puzzle_Solver
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Word_Puzzle_Solver
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=hpbar
Date                   :=30/04/2026
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/hpbar/Workspaces/HackerRank/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64/bin/windres.exe
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/mingw64/bin/ar.exe -r
CXX      := C:/mingw64/bin/g++.exe
CC       := C:/mingw64/bin/gcc.exe
CXXFLAGS :=  -O0 -gdwarf-2 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_HashTable.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_WordTable.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_SymbolTable.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ThreadPool.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_WordContainer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_WordPuzzleSolver.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_StringConverter.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_HashTable.cpp$(ObjectSuffix): src/HashTable.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/hpbar/Workspaces/HackerRank/Word_Puzzle_Solver/src/HashTable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_HashTable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_HashTable.cpp$(PreprocessSuffix): src/HashTable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_HashTable.cpp$(PreprocessSuffix) src/HashTable.cpp

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/hpbar/Workspaces/HackerRank/Word_Puzzle_Solver/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) src/main.cpp

$(IntermediateDirectory)/src_WordTable.cpp$(ObjectSuffix): src/WordTable.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/hpbar/Workspaces/HackerRank/Word_Puzzle_Solver/src/WordTable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_WordTable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_WordTable.cpp$(PreprocessSuffix): src/WordTable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_WordTable.cpp$(PreprocessSuffix) src/WordTable.cpp

$(IntermediateDirectory)/src_SymbolTable.cpp$(ObjectSuffix): src/SymbolTable.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/hpbar/Workspaces/HackerRank/Word_Puzzle_Solver/src/SymbolTable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SymbolTable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_SymbolTable.cpp$(PreprocessSuffix): src/SymbolTable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_SymbolTable.cpp$(PreprocessSuffix) src/SymbolTable.cpp

$(IntermediateDirectory)/src_ThreadPool.cpp$(ObjectSuffix): src/ThreadPool.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/hpbar/Workspaces/HackerRank/Word_Puzzle_Solver/src/ThreadPool.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ThreadPool.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ThreadPool.cpp$(PreprocessSuffix): src/ThreadPool.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ThreadPool.cpp$(PreprocessSuffix) src/ThreadPool.cpp

$(IntermediateDirectory)/src_WordContainer.cpp$(ObjectSuffix): src/WordContainer.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/hpbar/Workspaces/HackerRank/Word_Puzzle_Solver/src/WordContainer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_WordContainer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_WordContainer.cpp$(PreprocessSuffix): src/WordContainer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_WordContainer.cpp$(PreprocessSuffix) src/WordContainer.cpp

$(IntermediateDirectory)/src_WordPuzzleSolver.cpp$(ObjectSuffix): src/WordPuzzleSolver.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/hpbar/Workspaces/HackerRank/Word_Puzzle_Solver/src/WordPuzzleSolver.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_WordPuzzleSolver.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_WordPuzzleSolver.cpp$(PreprocessSuffix): src/WordPuzzleSolver.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_WordPuzzleSolver.cpp$(PreprocessSuffix) src/WordPuzzleSolver.cpp

$(IntermediateDirectory)/src_StringConverter.cpp$(ObjectSuffix): src/StringConverter.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/hpbar/Workspaces/HackerRank/Word_Puzzle_Solver/src/StringConverter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_StringConverter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_StringConverter.cpp$(PreprocessSuffix): src/StringConverter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_StringConverter.cpp$(PreprocessSuffix) src/StringConverter.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


