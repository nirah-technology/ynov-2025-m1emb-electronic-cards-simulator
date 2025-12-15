#include <iostream>

class ConfigurationManager {
private:
    ConfigurationManager() {
        std::cout << "ConfigurationManager: Instance créée (une seule fois !)." << std::endl;
        // Initialisation de l'état interne ici...
    }

    // Supprimer les opérations de copie et d'affectation
    ConfigurationManager(const ConfigurationManager&) = delete;
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;

    // État interne de l'objet Singleton
    std::string niveau_log_ = "INFO";

public:
    // Point d'accès global à l'instance unique
    static ConfigurationManager& getInstance() {
        static ConfigurationManager instance;
        return instance;
    }

    // Méthodes métier
    void setLog(const std::string& niveau) {
        niveau_log_ = niveau;
        std::cout << "ConfigurationManager: Niveau de log mis à jour : " << niveau_log_ << std::endl;
    }

    std::string getLog() const {
        return niveau_log_;
    }
};