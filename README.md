Question 1 ) Utilisation des arguments passés à la ligne de commande des programmes gettftp et puttftp pour obtenir les informations de requêtes (serveur et fichier)
Pour repondre à cette question il suffit de récuperer le nombre d'arguments et les arguments en eux même grâce aux fonctions write et snprintf

Question 2 ) Appel à getaddrinfo pour obtenir l’adresse du serveur ;

Notre serveur tftp est un serveur local sont adresse est donc 127.0.0.1 ou localhost le but va être de récupérer le nombre de processus le type de socket du serveur et la famille. Pour cela on va utiliser la structure addrinfo  
pour configurer et obtenir des informations nécessaires à la création et à la liaison d'une socket réseau.

  .ai_family = AF_INET;    spécifie le type d'adresses IP que l'on souhaite utiliser et AF_INET signifie que l'on souhaite utiliser le protocole IPv4. 
  .ai_socktype = SOCK_DGRAM; détermine le type de socket que l'on souhaite créer. SOCK_DGRAM indique que l'on veut une socket de type datagram, qui utilise le protocole UDP
  .ai_flags = AI_PASSIVE;   est utilisé pour définir des options spécifiques lors de l'appel à getaddrinfo.  AI_PASSIVE permet de lier la socket à toutes les adresses IP locales pour accepter les connexions entrantes.


A partir de la chaine de caractétère fournie en entrée (localhost) on va  remplir une structure addrinfo avec des informations utiles pour la création et l'utilisation d'une socket avec getaddrinfo.

Ensuite il suffit d'afficher à l'aide de pointeur la famille le nombre de processus et le type de socket du serveur.

Question 3 ) Réservation d’un socket de connexion vers le serveur


Pour cela on va crée une structure sockaddr_in pour donner un port et pour préciser que l'on veut utiliser uniquement les protocols IPV4.On va ensuite créer un socket client avec la fonction socket en lui précisant le protocol IPV4 et UDP puis on utilise 
la fonction connect pour connecter le socket du serveur au socket du client.


Question 4 )Construction d’une requête en lecture (RRQ) correctement formée, et envoi au serveur

On réutillise le code de la question précédente puis  on a juste a utilisé la fonction send qui est utilisée pour envoyer des données sur un socket. On a juste ensuite à verifier que le message est bien partie.
