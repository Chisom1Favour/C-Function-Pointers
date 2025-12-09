#include <stdio.h>
#include <stdlib.h>

typedef struct Pet
{
	const char *name;
	void (*speak)(struct Pet*);
} Pet;

Pet *createPet(const char *name, void (*speakFunc)(Pet*))
{
	Pet* pet = (Pet*)malloc(sizeof(Pet));
	pet->name = name;
	pet->speak = speakFunc;
	return pet;
}
void destroyPet(Pet* pet)
{
	free(pet);
}
void dogSpeak(Pet* pet)
{
	printf("%s says Woof!\n", pet->name);
}
void catSpeak(Pet* pet)
{
	printf("%s says 'Meow!'\n", pet->name);
}
void speak(Pet* pet)
{
	pet->speak(pet);
}

int main()
{
	Pet* fido = createPet("Fido", dogSpeak);
	Pet* simba = createPet("Simba", catSpeak);
	
	speak(fido);
	speak(simba);

	// cleanup; free resources
	destroyPet(fido);
	destroyPet(simba);
	return 0;
}
