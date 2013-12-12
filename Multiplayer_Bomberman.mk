##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Multiplayer_Bomberman
ConfigurationName      :=Debug
WorkspacePath          := "Z:\Programming\GithubRepositories\Multiplayer_Bomberman"
ProjectPath            := "Z:\Programming\GithubRepositories\Multiplayer_Bomberman"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Zephilinox
Date                   :=12/12/13
CodeLitePath           :="Z:\Programming\C++\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Multiplayer_Bomberman.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -lsfml-graphics -lsfml-window -lsfml-system 
IncludePath            := $(IncludeSwitch)Z:/Programming/C++/SFML-2.1/include  $(IncludeSwitch). $(IncludeSwitch)src $(IncludeSwitch)include $(IncludeSwitch)dll $(IncludeSwitch)Z:/Programming/C++/SFML-2.1/bin $(IncludeSwitch). $(IncludeSwitch)src $(IncludeSwitch)include $(IncludeSwitch)dll $(IncludeSwitch)fonts $(IncludeSwitch)textures $(IncludeSwitch)E:/Programming/C++/SFML-2.1/include $(IncludeSwitch)E:/Programming/C++/SFML-2.1/bin 
IncludePCH             := 
RcIncludePath          := $(IncludeSwitch)fonts $(IncludeSwitch)textures $(IncludeSwitch)src $(IncludeSwitch)include $(IncludeSwitch)dll 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                :=$(LibraryPathSwitch)Z:/Programming/C++/SFML-2.1/lib  $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)src $(LibraryPathSwitch)include $(LibraryPathSwitch)dll $(LibraryPathSwitch)fonts $(LibraryPathSwitch)textures $(LibraryPathSwitch)E:/Programming/C++/SFML-2.1/lib $(LibraryPathSwitch)E:/Programming/C++/SFML-2.1/bin 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=Z:\Programming\C++\CodeLite
UNIT_TEST_PP_SRC_DIR:=Z:\Programming\C++\CodeLite\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/src_ResourceManager$(ObjectSuffix) $(IntermediateDirectory)/src_Utility$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "Z:/Programming/GithubRepositories/Multiplayer_Bomberman/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/src_ResourceManager$(ObjectSuffix): src/ResourceManager.cpp $(IntermediateDirectory)/src_ResourceManager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "Z:/Programming/GithubRepositories/Multiplayer_Bomberman/src/ResourceManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ResourceManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ResourceManager$(DependSuffix): src/ResourceManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ResourceManager$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ResourceManager$(DependSuffix) -MM "src/ResourceManager.cpp"

$(IntermediateDirectory)/src_ResourceManager$(PreprocessSuffix): src/ResourceManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ResourceManager$(PreprocessSuffix) "src/ResourceManager.cpp"

$(IntermediateDirectory)/src_Utility$(ObjectSuffix): src/Utility.cpp $(IntermediateDirectory)/src_Utility$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "Z:/Programming/GithubRepositories/Multiplayer_Bomberman/src/Utility.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Utility$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Utility$(DependSuffix): src/Utility.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Utility$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Utility$(DependSuffix) -MM "src/Utility.cpp"

$(IntermediateDirectory)/src_Utility$(PreprocessSuffix): src/Utility.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Utility$(PreprocessSuffix) "src/Utility.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_ResourceManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_ResourceManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_ResourceManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Utility$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Utility$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Utility$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/Multiplayer_Bomberman"


