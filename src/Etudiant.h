#ifndef _ETUDIANT
#define _ETUDIANT


class Etudiant{

	public:

		Etudiant(int , int);//constructeur par défaut de la classe

		Etudiant(const Etudiant & e);//constructeur par copie de la classe

		~Etudiant();//destructeur de la classe

		unsigned int getClef();//fonction de retour du numéro de l'étudiant

		int getInfo();//fonction de retour de l'information associé à l'étudiant

		int info = 0;// age de l'étudiant


	private:
		unsigned int clef;//numéro de l'étudiant

		
};


#endif
