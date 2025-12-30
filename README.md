# MiniVoyage - Système de Réservation avec Patrons de Conception

## 📋 Description

MiniVoyage est un système de gestion de réservations permettant aux clients de :
- Gérer des réservations (hébergement, transport, excursions)
- Ajouter des modifications avec suivi temporel et coûts
- Consigner des commentaires et problèmes
- Générer des fichiers de journalisation

Les gestionnaires peuvent :
- Appliquer des rabais temporaires
- Effectuer des ajustements de prix permanents
- Ajouter des commentaires aux offres
- Calculer les statistiques de la base de données

## 🛠️ Technologies

- **Langage**: C++
- **IDE**: Visual Studio
- **Paradigme**: Programmation orientée objet
- **Focus**: Patrons de conception (Design Patterns)

## 🎯 Patrons de Conception Utilisés

- **Decorator** : Ajout dynamique de fonctionnalités aux réservations et offres (commentaires, modifications)
- **Composite** : Gestion hiérarchique des réservations complexes
- **Proxy** : Contrôle d'accès et gestion des offres
- **Factory** : Création d'objets de réservation

### Instructions
1. Cloner le repository

2. Ouvrir le fichier `LOG2400-TP4-MiniVoyage.sln` dans Visual Studio

3. Compiler le projet

4. Exécuter l'application

5. Vérifier les fichiers de sortie générés dans le répertoire du projet

## ✅ Fonctionnalités Principales
- ✨ Modifications de réservations avec traçabilité (date, heure, coûts)
- 💬 Système de commentaires client sur réservations
- 📝 Journalisation des affichages dans fichiers texte
- 💰 Rabais temporaires sur offres (via décorateur)
- 📊 Ajustements de prix permanents avec journalisation
- 🔢 Calcul du nombre total d'offres dans la BDOR
- 🏷️ Commentaires généraux sur offres par le gestionnaire
