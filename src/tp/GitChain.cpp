/*
Vous voulez développer un logiciel qui permet de récupérer du code source afin
de le déployer sur un serveur web.

Développer la chain de responsabilité qui réalise les étapes suivantes :

1. Lancer les tests unitaires
2. Lancer les tests de qualité
3. Lancer les tests de sécurité
4. Lancer les tests d'intégration
5. Lancer les tests End-To-End
6. Compiler le projet
7. Publier le projet
8. Déployer le projet

*/

#include <iostream>

class Step {
    public:
    virtual void process() = 0;
    virtual void set_next(Step* next_step) = 0;
};

class AbstractStep : public Step {
    protected:
    Step* next_step;

    public:
    void set_next(Step* next_step) override {
        if (this->next_step == nullptr) {
            this->next_step = next_step;
        }
    }
};

class LaunchUnitTestsStep : public AbstractStep {
    private:
        void launch_unit_tests() {
            for (int test_count = 0; test_count < 5; test_count++) {
                std::cout << "Launching UNIT-TESTS #" << test_count << "..." << std::endl;
                std::cout << "UNIT-TESTS #" << test_count << "successfully passed" << std::endl;
            }
        }
    
    public:
        void process() override {
            this->launch_unit_tests();

            if (this->next_step != nullptr) {
                this->next_step->process();
            }
        }
};

class LaunchQualityTestsStep : public AbstractStep {
    private:
        void launch_quality_tests() {
            for (int test_count = 0; test_count < 2; test_count++) {
                std::cout << "Launching QUALITY-TESTS using SonarQube #" << test_count << "..." << std::endl;
                std::cout << "QUALITY-TESTS using SonarQube #" << test_count << "successfully passed" << std::endl;
            }
        }
    
    public:
        void process() override {
            this->launch_quality_tests();

            if (this->next_step != nullptr) {
                this->next_step->process();
            }
        }
};


class LaunchSecurityTestsStep : public AbstractStep {
    private:
        void launch_security_tests() {
            for (int test_count = 0; test_count < 100; test_count++) {
                std::cout << "Launching SECURITY-TESTS using Kali #" << test_count << "..." << std::endl;
                std::cout << "SECURITY-TESTS using Kali #" << test_count << "successfully passed" << std::endl;
            }
        }
    
    public:
        void process() override {
            this->launch_security_tests();

            if (this->next_step != nullptr) {
                this->next_step->process();
            }
        }
};

class CompileStep : public AbstractStep {
    private:
        void launch_compilation() {
            std::cout << "Launching Compilation..." << std::endl;
            std::cout << "Compilation successfully terminated" << std::endl;
        }
    
    public:
        void process() override {
            this->launch_compilation();

            if (this->next_step != nullptr) {
                this->next_step->process();
            }
        }
};

class DeployBinarayStep : public AbstractStep {
    private:
        void launch_deployment() {
            std::cout << "Install application..." << std::endl;
            std::cout << "Application successfully installed" << std::endl;
        }
    
    public:
        void process() override {
            this->launch_deployment();

            if (this->next_step != nullptr) {
                this->next_step->process();
            }
        }
};

class GitPipeline {
    private:
        Step* step;
    
    public:
        GitPipeline(Step* step) : step(step) { }

        void run() {
            if (this->step != nullptr) {
               this->step->process(); 
            }
        }
};