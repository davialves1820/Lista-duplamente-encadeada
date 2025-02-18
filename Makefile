# Variáveis do compilador e flags de compilação
CXX = g++
CXXFLAGS = -Wall -Wextra -g -Iinclude

# Diretórios e arquivos
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)  # Encontrar todos os arquivos .cpp em src
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))  # Converter para arquivos .o
EXECUTABLE = $(BUILD_DIR)/programa.exe

# Regra principal (target): compila o programa
all: $(BUILD_DIR) $(EXECUTABLE)

# Regra para criar o executável
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS)

# Regra para compilar arquivos .cpp em arquivos .o, criando o diretório obj se necessário
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criação do diretório obj e build caso não existam
$(OBJ_DIR):
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# Limpeza dos arquivos gerados
clean:
	del /Q $(OBJECTS) $(EXECUTABLE)