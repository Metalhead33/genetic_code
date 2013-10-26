#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;


bool chance() {
  return rand() % 2 == 1;
}

enum dominance
{
    recessive = 1,
    dominant
};

enum a_type
{
    homozygote = 1,
    heterozygote
};

class allele
{
private:
    string display_name;
    dominance strength;
public:
    allele(string setname, dominance setstrength)
    {
        display_name = setname;
        strength = setstrength;
    };
    allele()
    {
        string setname = "N\\A";
        dominance setstrength = recessive;
    };
    static allele GetNull()
    {
        allele *res = new allele("N\\A",recessive);
        return *res;
    };
    string GetName(){ return display_name; }
    dominance GetStrength(){ return strength; }
};
allele a_dummy("N\\A", recessive);

class chromosome
{
private:
    string display_name;
    allele *allel1;
    allele *allel2;
    allele *ph_allel;
    a_type zygote;
public:
    void InitializeChroma(allele* setallel1, allele* setallel2)
    {
    allel1 = setallel1;
    allel2 = setallel2;
    if (allel1 == allel2)
        zygote = homozygote;
        else
        zygote = heterozygote;
    if (zygote = heterozygote)
        {
            if (allel1->GetStrength() < allel2->GetStrength())
            ph_allel = allel2;
            else
            ph_allel = allel1;}
        else
            ph_allel = allel1;
        ;}
    chromosome(string set_name, allele setallel1, allele setallel2)
    {
    display_name = set_name;
    allel1 = &setallel1;
    allel2 = &setallel2;
    if (allel1 == allel2)
        zygote = homozygote;
        else
        zygote = heterozygote;
    if (zygote = heterozygote)
        {
            if (allel1->GetStrength() < allel2->GetStrength())
            ph_allel = allel2;
            else
            ph_allel = allel1;}
        else
            ph_allel = allel1;
    };
    chromosome()
    {
    string set_name = "N/A";
    allele setallel1 = a_dummy;
    allele setallel2 = a_dummy;
    };
    static chromosome GetNull()
    {
    chromosome *res = new chromosome("N\\A",a_dummy,a_dummy);
    return *res;
    };
    string GetName() { return display_name; };
    void SetName(string set_name) { display_name = set_name; };
    a_type GetZygote() { return zygote; };
    allele *GetAllele1() { return allel1; };
    allele *GetAllele2() { return allel2; };
    void SetAllele1(allele setallel1) { allel1 = &setallel1; };
    void SetAllele2(allele setallel2) { allel1 = &setallel2; };
    allele *GetPhenoType() { return ph_allel; };
};
chromosome c_dummy("N\\A",a_dummy,a_dummy);

class person
{
private:
    string display_name;
    chromosome *paternal;
    chromosome *maternal;
    chromosome own;
    allele *paternal_chosen;
    allele *maternal_chosen;
public:
    void InitializeChromosome(string chrom_name,allele *father, allele *mother)
    {
        own.SetName(chrom_name+"'s chromosome");
        own.InitializeChroma(father,mother);
    }
    person(string setname, chromosome *set_father, chromosome *set_mother)
    {
        display_name = setname;
        paternal = set_father;
        maternal = set_mother;
        srand(time(0));
        if (chance() == 1)
        paternal_chosen = paternal->GetAllele1();
        else
        paternal_chosen = paternal->GetAllele2();
        if (chance() == 1)
        maternal_chosen = maternal->GetAllele1();
        else
        maternal_chosen = maternal->GetAllele2();
        InitializeChromosome(display_name,paternal_chosen,maternal_chosen);
    };
    person()
    {
        string setname = "No one";
        chromosome set_father = c_dummy;
        chromosome set_mother = c_dummy;
    };
    static person GetNull()
    {
        person *res = new person("No one",&c_dummy,&c_dummy);
        return *res;
    };
    string GetName() {return display_name; }
    chromosome GetChrom() {return own; }
    chromosome GetFather() {return *paternal; }
    chromosome GetMother() {return *maternal; }
};
person p_dummy("No one",&c_dummy,&c_dummy);

int main()
{
allele a_blondhair("Blond Hair", recessive);
allele a_blackhair("Black Hair", dominant);
chromosome c_blond("Blond-hair Chromosome",a_blondhair,a_blondhair);
chromosome c_black("Black-hair Chromosome",a_blackhair,a_blackhair);
chromosome c_mixed("Black-blond mixed",a_blackhair,a_blondhair);
person p_John("John",&c_mixed,&c_mixed);
cout << "Name: " << p_John.GetName() << endl;
cout << p_John.GetChrom().GetAllele1()->GetStrength() << endl;
cout << "Primary allele: " << p_John.GetChrom().GetAllele1()->GetName() << endl;
cout << "Secondary allele: " << p_John.GetChrom().GetAllele2()->GetName() << endl;
cout << "Phenotype (Surfacing allele): " << p_John.GetChrom().GetPhenoType()->GetName() << endl;
cout << "Mother's hair colour: " << p_John.GetMother().GetPhenoType()->GetName() << endl;
cout << "Father's hair colour: " << p_John.GetFather().GetPhenoType()->GetName() << endl;
    return 0;
    };
