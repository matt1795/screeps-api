from conans import ConanFile, CMake, tools


class ScreepsApiConan(ConanFile):
    author = "Matthew Knight"
    description = "C++ API for screeps"
    generators = ["virtualenv"]
    license = "MIT"
    name = "screeps-api"
    settings = {"os": ["Emscripten"]}
    topics = ("conan", "screeps", "emscripten", "js", "javascript")
    url = "https://github.com/matt1795/screeps-api.git"
    version = "0.1"

    def source(self):
        self.run("git clone https://github.com/matt1795/screeps-api.git")

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
    
    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def imports(self):
        self.copy("*.html", "", "bin")
        self.copy("*.wasm", "", "bin")
        self.copy("*.js", "", "bin")
