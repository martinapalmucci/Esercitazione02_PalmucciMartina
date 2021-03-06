// Esercitazione02_PalmucciMartina.cpp

// Nome e Cognome: Martina Palmucci
// Numero di matricola: 097506
// Classe: L-35 Matematica e Applicazioni

// ESERCITAZIONE N°2
// LA TORRE DI HANOI

// Questo programma risolve il rompicapo della Torre di Hanoi.
// Prende in input dall'utente un numero intero positivo
// restituisce in output la serie di sequenze da svolgere
// per risolvere il puzzle.
// Alla fine calcola il tempo impiegato.


#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <chrono>

// DICHIARAZIONI ED INIZIALIZZAZIONI

// - funzioni
int get_rod();								// chiede il numero di dischi
void HanoiTower(int, char, char, char);		// stampa le mosse per risolvere il gioco

// CORPO DEL CODICE
int main()
{
	std::cout << "Benvenuto nel gioco della TORRE DI HANOI\n" << std::endl;
	int n = get_rod(); // numero di dischi

		auto start = std::chrono::high_resolution_clock::now();		// salva il tempo di inizio calcolo
 
	HanoiTower(n, 'A', 'C', 'B');  // A, B, C sono i nomi delle asticelle 

		auto end = std::chrono::high_resolution_clock::now();		// salva in tempo di fine calcolo
	
		std::chrono::duration<float> duration = end - start;		// durata dell'esecuzione
		std::cout << "Tempo impiegato " << duration.count() << " secondi" << std::endl;

	return 0;
}


// FUNZIONI

int get_rod()	//Funzione che chiede all'utente
				// il numero di dischi
				// con cui vuole giocare.
				// Non prende in input nulla,
				// restituisce il numero dei dischi.
{
	int n; // numero di dischi

	do	// chiede all'utende un numero di dischi
		// accettabile
		// (numero positivo)
	{
		std::cout << "Inserisci il numero di dischi con cui vuoi giocare: ";
		std::cin >> n; // chiede in in

		if (n <= 0) // se non è accettabile
					// stampo un messaggio di errore
			std::cout << "Numero dischi non valido.\n" << std::endl;

	} while (n <= 0);

	std::cout << std::endl
		<< "Giochiamo con " << n << " dischi!\n" << std::endl;
	return n;
}

void HanoiTower(int n, char from_rod, char to_rod, char aux_rod)
	// funzione che risolve il puzzle della Torre di Hanoi
	// prende in input il numero di dischi
	// il piolo di origine
	// il piolo di destinazione e
	// il piolo ausiliario
	// restituisce in output video
	// le mosse di gioco
{
	if (n == 1) // muove il primo disco
	{
		printf(" Si muove il disco 1 dal piolo %c al piolo %c \n", from_rod, to_rod);
		return;
	}
	HanoiTower(n - 1, from_rod, aux_rod, to_rod); // prima ricorsività
	printf(" Si muove il disco %d dal piolo %c al piolo %c \n", n, from_rod, to_rod); // muove l'n-esimo disco
	HanoiTower(n - 1, aux_rod, to_rod, from_rod); // seconda ricorsività
}

// The End.
