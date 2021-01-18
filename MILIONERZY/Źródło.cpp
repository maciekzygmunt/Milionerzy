#include<iostream>
#include<locale.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>


using namespace std;
int main() {
    setlocale(LC_CTYPE, "Polish");
    srand(time(0));
    int index;
    int licznikDobrychOdpowiedzi = 0;
    int licznikZlychOdpowiedzi = 0;
    string pytania[100];
    char odpowiedzi[100];
    string odpowiedzi_pobrane[100];
    fstream wyniki; //zmienna na wyniki w pliku
    fstream pytania_w_pliku; //zmienna na pytania w pliku
    fstream odpowiedzi_w_pliku; //zmienna na odpowiedzi w pliku
    string nick; //zmienna na nick do wyniów
    string pytaniapolnapol[100];
    int polnapol = 0;
    int podwojnaodpowiedz = 0;
    int zamianapytania = 0;
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //latwe
    /*
    pytania[] = ":\na. \t b. \nc. \t d. \n";
    odpowiedzi[] = '';
    */
    /*
    pytania[9] = "";
    odpowiedzi[9] = '';
    */

    pytania[1] = "Który z tych ułamków to ułamek niewłaściwy?:\na. 3/4\tb. 0,3\nc. 4/3\td. 0,33\n";
    odpowiedzi[1] = 'c';
    pytania[2] = "Twarz i pocałunek to?:\na. morda\tb. całus\nc. cmok \td. buziak\n";
    odpowiedzi[2] = 'd';
    pytania[3] = "Do czego służy krawcowej blaszka na palec?:\na. do ochrony palca\t         b. do prucia fastryg\nc. do obrzucania dziurek\t d. do nawlekania igieł\n";
    odpowiedzi[3] = 'd';
    pytania[4] = "Wskaż błąd.:\na. wymyślić coś naprędce\t b. schodzić na manowce\nc. nadwerężyć plecy\t         d. poddać coś w wątpliwość\n";
    odpowiedzi[4] = 'd';
    pytania[5] = "Kłócić się z kimś, robić mu na złośliwości to pójść z nim:\na. w sukurs\t b. jak w dym\nc. w konkury\t d. na udry\n";
    odpowiedzi[5] = 'd';
    pytania[6] = "Co ma lodowiec?:\na. gały\t b. jęzor\nc. girę\t d. kałdun\n";
    odpowiedzi[6] = 'b';
    pytania[7] = "Polskie ruskie pierogi nadziewane są?:\na. białą i czerwoną kapustą\t b. biała i czerwoną fasolą\nc. białym i czerwonym mięsem\t d. ziemniakami i serem\n";
    odpowiedzi[7] = 'd';
    pytania[8] = "W jakim mieście odbywały się słynne spotkania naukowo-literackie zwane obiadami czwartkowymi?:\na. w Gnieźnie\t b. w Puławach\nc. w Warszawie\t d. w Krakowie\n";
    odpowiedzi[8] = 'c';
    pytania[9] = "Kto napisał „Would you know my name if I saw you in heaven”I to śpiewa z gitarą?:\na. Soyka\t b. Phil Collins\nc. Eric Clapton\t d. Sting\n";
    odpowiedzi[9] = 'c';
    pytania[10] = "Czego mogła użyczyć Dafne po przemianie?:\na. laski wanilii\t b. listka bobkowego\nc. kryształu soli\t d. kory cynamonu\n";
    odpowiedzi[10] = 'b';
    pytania[11] = "Na krechę:\na. powoływał się T.Mazowiecki\t b. skacze temperatura\nc. zjeżdżają narciarze\t         d. czekał przysłowiowy Matysek\n";
    odpowiedzi[11] = 'c';
    pytania[12] = "Zagalopować się to posunąć się:\na. w latach\t b. nieco na koniu\nc. za daleko\t d. o włos\n";
    odpowiedzi[12] = 'c';
    pytania[13] = "Nie ma żadnych państw ościennych:\na. Polska\t b. Portugalia\nc. Serbia\t d. Islandia\n";
    odpowiedzi[13] = 'd';
    pytania[14] = "Który instrument stroi muzyk?:\na. tamburyn\t b. kocioł\nc. okarynę\t d. czynele\n";
    odpowiedzi[14] = 'b';
    pytania[15] = "Z gry na jakim instrumencie słynie Czesław Mozil?:\na. na kornecie\t b. na akordeonie\nc. na djembe\t d. na saksofonie\n";
    odpowiedzi[15] = 'b';
    pytania[16] = "Co ukoi nerwy i zastąpi cytrynę?:\na. melisa lekarska\t b. mięta pieprzowa\nc. jaskółcze ziele\t d. ziele angielskie \n";
    odpowiedzi[16] = 'a';
    pytania[17] = "Co kroimy w piórka?:\na. cebulę\t b. natkę pietruszki\nc. buraki\t d. seler naciowy \n";
    odpowiedzi[17] = 'a';
    pytania[18] = "Jaki kolor ma dodawany do gum do żucia, pasta do zębów, cukru pudru i wielu innych produktów dwutlenku tytanu?:\na. zielony\t b. czerwony\nc. czarny\t d. biały \n";
    odpowiedzi[18] = 'd';
    pytania[19] = "Wszystkie śmieci rozkładają się kilkaset lat, ale najdłużej:\na. pampers\t         b. plastikowa torebka\nc. żyłka wędkarska\t d. aluminiowa puszka \n";
    odpowiedzi[19] = 'c';
    pytania[20] = "Który z indeksów reprezentuje Giełdę Papierów Wartościowych w Warszawie?:\na. DAX\t b. NASDAQ\nc. WIG\t d. Dow Jones \n";
    odpowiedzi[20] = 'c';
    pytania[21] = "Politycy łączą w popularna piramidkę:\na. mandaty poselskie\t b. proletariuszy wszystkich krajów\nc. palce dłoni\t         d. punkty wystąpienia \n";
    odpowiedzi[21] = 'c';
    pytania[22] = "Jaka część mowy odpowiada na pytania: kto, co?:\na. przymiotnik\t b. czasownik\nc. rzeczownik\t d. przysłówek \n";
    odpowiedzi[22] = 'c';
    pytania[23] = "Co powstanie z wody, gdy ją zamrozimy?:\na. para\t b. chmura\nc. lód\t d. mleko \n";
    odpowiedzi[23] = 'c';
    pytania[24] = "Jaka legenda jest związana z Warszawą?:\na. o smoku wawelskim \t                 b. o Popielu\nc. o Wandzie, co nie chciała Niemca\t d. o syrence \n";
    odpowiedzi[24] = 'd';
    pytania[25] = "Kto ma łeb obdarty?:\na. kto późno przychodzi  \t b. kto jest krótko ostrzyżony \nc. kto gra w karty \t         d. kto ma nos zadarty \n";
    odpowiedzi[25] = 'c';
    pytania[26] = "Jak się pisze wyraz (rz/ż)(ó/u)raw? :\na. ż, ó   \t b. rz, u  \nc. rz, u  \t d. ż, u \n";
    odpowiedzi[26] = 'd';
    pytania[27] = "Co nie jest nazwą stylu pływackiego?:\na. rekin \t b. kraul \nc. żabka \t d. delfin \n";
    odpowiedzi[27] = 'a';
    pytania[28] = "Która z tych małp jest największa?:\na. orangutan \t b. kapucynka \nc. szympans \t d. goryl \n";
    odpowiedzi[28] = 'd';
    pytania[29] = "Jaki jest numer straży pożarnej?:\na. 999 \t b. 997 \nc. 998 \t d. 996 \n";
    odpowiedzi[29] = 'c';
    pytania[30] = "W jakim mieście jest Wawel?:\na. we Wrocławiu \t b. w Warszawie \nc. w Poznaniu \t         d. w Krakowie \n";
    odpowiedzi[30] = 'd';
    pytania[31] = "Gdzie leży Arktyka?:\na. wokół bieguna południowego \t b. wokół bieguna północnego \nc. na równiku \t                 d. na Księżycu \n";
    odpowiedzi[31] = 'b';
    pytania[32] = "Trzy z czterech nazw odnoszą się do tego samego oceanu. Która go nie dotyczy?:\na. Atlantyk \t b. Ocean Wielki \nc. Pacyfik \t d. Spokojny \n";
    odpowiedzi[32] = 'a';
    pytania[33] = "Które ze świąt dzieli najmniejsza liczba dni od Andrzejek?:\na. Boże Narodzenie \t b. Wielkanoc \nc. Zaduszki \t         d. Święto Trzech Króli \n";
    odpowiedzi[33] = 'a';
    pytania[34] = "Ile rodzonych córek miała macocha Kopciuszka w baśni braci Grimm?:\na. dwie \t b. trzy \nc. cztery \t d. pięć \n";
    odpowiedzi[34] = 'a';
    pytania[35] = "Jak to dalej szło? „Opowiem ci bajkę, jak kot palił fajkę, a kocica papierosa… :\na. kocięta zaś skręta \t b. w fifce, byle dalej nosa \nc. upaliła kawał nosa \t d. te koty zeszły z drogi cnoty \n";
    odpowiedzi[35] = 'c';
    pytania[36] = "Czym Chińczycy tradycyjnie jadają potrawy z ryżu?:\na. łyżkami \t b. wykałaczkami \nc. widelcami \t d. pałeczkami \n";
    odpowiedzi[36] = 'd';
    pytania[37] = "Ile miesięcy liczy kwartał?:\na. 2 \t b. 3 \nc. 4 \t d. 5 \n";
    odpowiedzi[37] = 'b';
    //srednie
    pytania[38] = "Kim z zawodu jest Frank Underwood – główny bohater serialu „House of Cards?:\na. kierowcą rajdowym \t b. architektem \nc. politykiem \t         d. pokerzystą \n";
    odpowiedzi[38] = 'c';
    pytania[39] = "Sążeń to antropometryczna miara długości równa rozpiętości:\na. pięt \t          b. ramion \nc. ramion cyrkla \t  d. zainteresowań \n";
    odpowiedzi[39] = 'b';
    pytania[40] = "Co jest charakterystyczne w umaszczeniu doga niemieckiego zwanego arlekinem?:\na. czarna podpalana sierść \t  b. równo rozmieszczone pręgi \nc. czarne łaty na białym tle \t  d. jednolity złoty kolor \n";
    odpowiedzi[40] = 'c';
    pytania[41] = "Dziko rośnie w Polsce i jest lianą:\na. aktinidia smakowita \t  b. bluszcz pospolity \nc. malina właściwa \t  d. grab \n";
    odpowiedzi[41] = 'b';
    pytania[42] = "W papieskim błogosławieństwie „Urbi et Orbi” - urbi znaczy miastu, a orbi?:\na. wsi \t          b. światu \nc. słońcu \t  d. obieżyświatom \n";
    odpowiedzi[42] = 'b';
    pytania[43] = "Słynne zwierzę senator za panowania cesarza Kaliguli to:\na. koń \t          b. wąż \nc. kozioł \t  d. kanarek \n";
    odpowiedzi[43] = 'a';
    pytania[44] = "Który z półwyspów nie ma stałych rzek?:\na. Półwysep Skandynawski \t b. Półwysep Jutlandzki \nc. Półwysep Indyjski \t         d. Półwysep Arabski \n";
    odpowiedzi[44] = 'd';
    pytania[45] = "Co ma łapawica?:\na. brak zahamowań \t         b. „futerał” na kciuk \nc. stały potencjał infekcyjny \t d. składany miech \n";
    odpowiedzi[45] = 'b';
    pytania[46] = "Jan Kochanowski po śmierci Zygmunta Augusta był zwolennikiem i uczestniczył w elekcji:\na. Augusta III Sasa \t b. Jana III Sobieskiego \nc. Jana II Kazimierza \t d. Henryka Walezego \n";
    odpowiedzi[46] = 'd';
    pytania[47] = "Okulbaczyć to:\na. sprawić sobie binokle \t b. zaszczepić drzewko \nc. kontrolować okulistów \t d. osiodłać wierzchowca \n";
    odpowiedzi[47] = 'd';
    pytania[48] = "Która z biblijnych postaci nosi przydomek Iskariota?:\na. Mojżesz \t b. Judasz \nc. Noe \t         d. Abel \n";
    odpowiedzi[48] = 'b';
    pytania[49] = "Których bierek w bierkach jest najwięcej?:\na. wioseł \t b. bosaków \nc. trójzębów \t d. oszczepów \n";
    odpowiedzi[49] = 'd';
    pytania[50] = "Wszystkie cztery brzmią tak samo, a jedno wygląda i brzmi inaczej odwołuje się do prawdy. Które?:\na. banał \t b. komunał \nc. frazes \t d. truizm \n";
    odpowiedzi[50] = 'd';
    pytania[51] = "Komiksowym 'dzieckiem' rysownika Boba Kane'a jest:\na. Superman \t b. Batman \nc. Spider-Man \t d. Captain Ameryka \n";
    odpowiedzi[51] = 'b';
    pytania[52] = "Likier maraskino produkuje się z maraski, czyli odmiany:\na. wiśni \t b. jabłoni \nc. figi \t d. gruszy \n";
    odpowiedzi[52] = 'a';
    pytania[53] = "Który utwór Juliusza Słowackiego napisany jest prozą?:\na. „Godznia myśli” \t b. „W Szwajcarii” \nc. „Anhelli” \t         d. „Arabi” \n";
    odpowiedzi[53] = 'c';
    pytania[54] = "Który ssak się nie spoci?:\na. owca \t b. koń \nc. człowiek \t d. królik \n";
    odpowiedzi[54] = 'd';
    pytania[55] = "Kogo dotyczy gamofobia?:\na. kandydatów do pracy \t         b. przyszłych małżonków \nc. uczniów przed maturą \t d. graczy na giełdzie \n";
    odpowiedzi[55] = 'b';
    pytania[56] = "Pad to najdłuższa rzeka:\na. Hiszpanii \t b. Portugalii \nc. Grecji \t d. Włoch \n";
    odpowiedzi[56] = 'd';
    pytania[57] = "Który smerf na ramieniu wytatuowane serce przebitą strzałą?:\na. maruda \t b. osiłek \nc. ważniak \t d. ciamajda \n";
    odpowiedzi[57] = 'b';
    pytania[58] = "Co tłusty krem potrafi zostawić na skórze?:\na. koncert \t         b. sztukę \nc. operę mydlaną \t d. film \n";
    odpowiedzi[58] = 'd';
    pytania[59] = "Za co przytulają hajs snugglersi?:\na. za przytulanie \t b. za lanie \nc. za kasę \t         d. za masę \n";
    odpowiedzi[59] = 'a';
    pytania[60] = "Kogo uratowała Calineczka?:\na. kreta \t b. jaskółkę \nc. pingwina \t d. żabę \n";
    odpowiedzi[60] = 'b';
    pytania[61] = "Ile jest znaków zodiaku?:\na. 12  \t b. 15 \nc. 16 \t d. 10 \n";
    odpowiedzi[61] = 'a';
    pytania[62] = "Do ilu punktów liczy się set w tenisie stołowym?:\na. 21  \t b. 25 \nc. 31 \t d. 20 \n";
    odpowiedzi[62] = 'a';
    pytania[63] = "Jakie są najwyższe góry na świecie?:\na. Tatry \t b. Himalaje \nc. Pireneje \t d. Alpy \n";
    odpowiedzi[63] = 'b';
    pytania[64] = "Który z podanych instrumentów nie należy do grupy aerofonów?:\na. obój \t b. tuba \nc. dudy \t d. żele \n";
    odpowiedzi[64] = 'd';
    pytania[65] = "Wafel pieczony z delikatnego ciasta w specjalnych foremkach to:\na. bajgiel \t b. andrut \nc. bakława \t d. beza \n";
    odpowiedzi[65] = 'b';
    pytania[66] = "Które z określeń nie oznacza wysłannika?:\na. emisariusz \t b. kurier \nc. poseł \t d. ordyna \n";
    odpowiedzi[66] = 'd';
    pytania[67] = "Tytułowa wataha z serialu wyreżyserowanego między innymi przez Kasię Adamik to:\na. wilcza rodzina \t b. rosyjscy szpiedzy \nc. strażnicy graniczni \t d. uchodźcy ze Wschodu \n";
    odpowiedzi[67] = 'c';
    //trunde
    pytania[68] = "Jaki instrument wykorzystał wędrowny szczurołap, który w XIII wieku miał wyprowadzić szkodniki z Hameln?:\na. Bęben \t b. Flet \nc. Puzon \t d. Harfę \n";
    odpowiedzi[68] = 'b';
    pytania[69] = "Konne tramwaje najwcześniej pojawiły się w Warszawie, a elektryczne?:\na. też w Warszawie \t b. w Bytomiu \nc. w Krakowie \t         d. we Wrocławiu \n";
    odpowiedzi[69] = 'd';
    pytania[70] = "Wyrazy srebro i pieniądze brzmią tak samo, ale tylko:\na. po niemiecku \t b. po rosyjsku \nc. po angielsku \t d. po francusku \n";
    odpowiedzi[70] = 'd';
    pytania[71] = "Przykładem transhumancji jest:\na. wypędzanie owiec na hale \t b. klonowanie zwierząt \nc. mit o Minotaurze \t         d. galwanizowanie trupa \n";
    odpowiedzi[71] = 'a';
    pytania[72] = "Symultanę rozgrywa się:\na. w tenisie ziemnym \t b. w szachach \nc. w zapasach \t         d. w piłce nożnej \n";
    odpowiedzi[72] = 'b';
    pytania[73] = "W 1937 r. w ramach pomocy generałowi Franco baskijską stolicę Guernicę prawie do cna zniszczyły bombardowania:\na. Luftwaffe \t                 b. Wojenno-Wozdusznych Sił \nc. United States Air Forces \t d. Royal Air Force \n";
    odpowiedzi[73] = 'a';
    pytania[74] = "Na szlaku Orlich Gniazd natrafimy na liczne zamki obronne budowane na skalistych, wapiennych wzgórzach. Jednym z nich jest zamek:\na. w Olsztynie \t b. w Gnieźnie \nc. w Malborku \t d. w Łańcucie \n";
    odpowiedzi[74] = 'a';
    pytania[75] = "„Jako to świadczymy, jako Anka zabiła Maciejowi wieprz i na wągrodzie mu nie dała paść” – to wyimek z tekstu:\na. roty wojskowej \t b. roty sądowej \nc. roty ślubnej \t d. „Roty” Marii Konopnickiej \n";
    odpowiedzi[75] = 'b';
    pytania[76] = "Kto jest mistrzem tego samego oręża, w jakim specjalizowała się mitologiczna Artemida?:\na. Zorro \t b. Legolas \nc. Don Kichot \t d. Longinus Podbipięty \n";
    odpowiedzi[76] = 'b';
    pytania[77] = "O ile oczu mniej ma mitologiczny Polifem od mitologicznego olbrzyma Argusa?:\na. o dziewięćdziesiąt dziewięć \t b. o dziewięćdziesiąt osiem \nc. o jedno \t                 d. o dwoje \n";
    odpowiedzi[77] = 'a';
    pytania[78] = "Skąd pochodził Conan Barbarzyńca?:\na. z Rivii \t b. z Oz \nc. z Mordoru \t d. z Cimmerii \n";
    odpowiedzi[78] = 'd';
    pytania[79] = "Co według Leszka Kołakowskiego jest sklepieniem domu, w którym duch ludzki mieszka?:\na. Rozum \t b. Bóg \nc. Miłość \t d. Czas \n";
    odpowiedzi[79] = 'd';
    pytania[80] = "Odrażający drab z Kabaretu Starszych Panów dubeltówkę weźmie, wyjdzie i...:\na. rach-ciach! \t b. buch, buch! \nc. z rur dwór \t d. bum w brzuch \n";
    odpowiedzi[80] = 'b';
    pytania[81] = "Co widnieje na fladze Azorów?:\na. pies \t b. psy \nc. jastrząb \t d. jastrzębie\n";
    odpowiedzi[81] = 'c';
    pytania[82] = "Różańcową tajemnicą chwalebną nie jest...:\na. Wniebowzięcie Matki Boskiej \t b. Zmartwychwstanie Jezusa \nc. Śmierć Jezusa na krzyżu \t d. Zesłanie Ducha Świętnego\n";
    odpowiedzi[82] = 'c';
    pytania[83] = "Tylko jedno zawiera utarty zwrot. Które?:\na. zebra pasi się na pasach \t b. droga jeży się trudnością \nc. licha lisi się sprytem \t d. jęki zajęczą się żałośnie\n";
    odpowiedzi[83] = 'b';
    pytania[84] = "Choroba łokcia dotycząca mięśni zginaczy, na którą cierpią dentyści, księgowi i informatycy, to tak zwany łokieć:\na. golfisty \t b. kierowcy kabrioletu \nc. pływaka \t d. skoczka narciarskiego\n";
    odpowiedzi[84] = 'a';
    pytania[85] = "Gdzie w 16 miesięcy włókniarkę zmieniono w kosmonautkę?:\na. w Chinach \t b. w USA \nc. w ZSRR \t d. w Rumunii\n";
    odpowiedzi[85] = 'c';
    pytania[86] = "Jaki jest kod pocztowy Kluczborku?:\na. 46-203 \t b. 43-370 \nc. 46-201 \t d. 40-200\n";
    odpowiedzi[86] = 'a';
    pytania[87] = "Na akord można:\na. spać \t b. pracować \nc. śpiewać \t d. podróżować\n";
    odpowiedzi[87] = 'b';
    pytania[88] = "Co kaftan bezpieczeństwa ma znacznie dłuższe niż zwykły kaftan?:\na. przód \t b. rękawy \nc. tył \t         d. kołnierz\n";
    odpowiedzi[88] = 'b';
    pytania[89] = "Kto na igrzyskach olimpijskich w Pjongczangu nie mógł startować pod flagą własnego kraju?:\na. Kanadyjczycy \t b. Szwedzi \nc. Rosjanie \t         d. Chińczycy\n";
    odpowiedzi[89] = 'c';
    pytania[90] = "Jak to dalej szło? „Góralu, czy ci nie żal…:\na. „na wódkę wydawać szmal” \t         b. „podrzucać lasów i hal” \nc. „odchodzić od stron ojczystych” \t d. „religi zostawiać lesistych”\n";
    odpowiedzi[90] = 'c';
    pytania[91] = "Co łączy rowerowa szprycha?:\na. obręcz z dętką \t b. dętkę z piastą \nc. piastę z obręczą \t d. obręcz z widelcem\n";
    odpowiedzi[91] = 'c';
    pytania[92] = "Suspens to chwyt stosowany:\na. w zapasach \t                 b. w grze na gitarze \nc. we wspinaczce klasycznej \t d. w filmach\n";
    odpowiedzi[92] = 'd';
    pytania[93] = "Lew zabity przez Ramona Marcedera to:\na. Simba \t b. Tołstoj \nc. Trocki \t d. Mufasa\n";
    odpowiedzi[93] = 'c';
    pytania[94] = "Który z wymienionych nie wystąpił w filmie fabularnym przed prezydenturą?:\na. Donald Trump \t b. Ronald Reagan \nc. Lech Kaczyński \t d. Valcav Havel\n";
    odpowiedzi[94] = 'd';
    pytania[95] = "Jak nazywa się amerykańska baza wojskowa na Kubie?:\na. Santa Clara \t b. Bayamo \nc. Guantanamo \t d. Matanzas\n";
    odpowiedzi[95] = 'c';
    pytania[96] = "Gdzie produkowany jest od 1835 roku włoski wermut Cinzano (rodzaj wina)?:\na. w Turynie \t         b. w Wenecji \nc. w Mediolanie \t d. we Florencji\n";
    odpowiedzi[96] = 'a';
    pytania[97] = "Kto był malarzem króla Filipa IV Habsburga?:\na. Marcello Bacciarelli \t b. Jan van Eyck \nc. Diego Velázquez \t         d. Jacques-Louis David\n";
    odpowiedzi[97] = 'c';
    pytania[98] = "Ile to jest 1111 razy 1111, jeśli 1 razy 1 to 1, a 11 razy 11 to 121?:\na. 12321 \t b. 1 234 321 \nc. 111 111 111 \t d. 123 434 321\n";
    odpowiedzi[98] = 'b';
    pytania[99] = "Symbol waluty euro to stylizowana grecka litera. Która?:\na. beta \t b. heta \nc. eta \t         d. epsilon\n";
    odpowiedzi[99] = 'd';





    pytaniapolnapol[1] = "Który z tych ułamków to ułamek niewłaściwy?:\n-. 3/4\tb. 0,3\nc. 4/3\t-. 0,33\n";
    pytaniapolnapol[2] = "Twarz i pocałunek to?:\n-. morda\tb. całus\n-. cmok \td. buziak\n";
    pytaniapolnapol[3] = "Do czego służy krawcowej blaszka na palec?:\na. do ochrony palca\t         -. do prucia fastryg\n-. do obrzucania dziurek\t d. do nawlekania igieł\n";
    pytaniapolnapol[4] = "Wskaż błąd.:\n-. wymyślić coś naprędce\t -. schodzić na manowce\nc. nadwerężyć plecy\t         d. poddać coś w wątpliwość\n";
    pytaniapolnapol[5] = "Kłócić się z kimś, robić mu na złośliwości to pójść z nim:\n-. w sukurs\t -. jak w dym\nc. w konkury\t d. na udry\n";
    pytaniapolnapol[6] = "Co ma lodowiec?:\n-. gały\t b. jęzor\nc. girę\t -. kałdun\n";
    pytaniapolnapol[7] = "Polskie ruskie pierogi nadziewane są?:\n-. białą i czerwoną kapustą\t b. biała i czerwoną fasolą\n-. białym i czerwonym mięsem\t d. ziemniakami i serem\n";
    pytaniapolnapol[8] = "W jakim mieście odbywały się słynne spotkania naukowo-literackie zwane obiadami czwartkowymi?:\na. w Gnieźnie\t -. w Puławach\nc. w Warszawie\t -. w Krakowie\n";
    pytaniapolnapol[9] = "Kto napisał „Would you know my name if I saw you in heaven”I to śpiewa z gitarą?:\n-. Soyka\t -. Phil Collins\nc. Eric Clapton\t d. Sting\n";
    pytaniapolnapol[10] = "Czego moga użyczyć Dafne po przemianie?:\n-. laski wanilii\t b. listka bobkowego\n-. kryształu soli\t d. kory cynamonu\n";
    pytaniapolnapol[11] = "Na krechę:\na. powoływał się T.Mazowiecki\t -. skacze temperatura\nc. zjeżdżają narciarze\t         -. czekał przysłowiowy Matysek\n";
    pytaniapolnapol[12] = "Zagalopować się to posunąć się:\n-. w latach\t -. nieco na koniu\nc. za daleko\t d. o włos\n";
    pytaniapolnapol[13] = "Nie ma żadnych państw ościennych:\n-. Polska\t -. Portugalia\nc. Serbia\t d. Islandia\n";
    pytaniapolnapol[14] = "Który instrument stroi muzyk?:\n-. tamburyn\t b. kocioł\nc. okarynę\t -. czynele\n";
    pytaniapolnapol[15] = "Z gry na jakim instrumencie słynie Czesław Mozil?:\n-. na kornecie\t b. na akordeonie\nc. na djembe\t -. na saksofonie\n";
    pytaniapolnapol[16] = "Co ukoi nerwy i zastąpi cytrynę?:\na. melisa lekarska\t -. mięta pieprzowa\nc. jaskółcze ziele\t -. ziele angielskie \n";
    pytaniapolnapol[17] = "Co kroimy w piórka?:\na. cebulę\t -. natkę pietruszki\nc. buraki\t -. seler naciowy \n";
    pytaniapolnapol[18] = "Jaki kolor ma dodawany do gum do żucia, pasta do zębów, cukru pudru i wielu innych produktów dwutlenku tytanu?:\na. zielony\t -. czerwony\n-. czarny\t d. biały \n";
    pytaniapolnapol[19] = "Wszystkie śmieci rozkładają się kilkaset lat, ale najdłużej:\n-. pampers\t         b. plastikowa torebka\nc. żyłka wędkarska\t -. aluminiowa puszka \n";
    pytaniapolnapol[20] = "Który z indeksów reprezentuje Giełdę Papierów Wartościowych w Warszawie?:\n-. DAX\t b. NASDAQ\nc. WIG\t -. Dow Jones \n";
    pytaniapolnapol[21] = "Politycy łączą w popularna piramidkę:\n-. mandaty poselskie\t b. proletariuszy wszystkich krajów\nc. palce dłoni\t         -. punkty wystąpienia \n";
    pytaniapolnapol[22] = "Jaka część mowy odpowiada na pytaniapolnapol: kto, co?:\n-. przymiotnik\t b. czasownik\nc. rzeczownik\t -. przysłówek \n";
    pytaniapolnapol[23] = "Co powstanie z wody, gdy ją zamrozimy?:\na. para\t -. chmura\nc. lód\t -. mleko \n";
    pytaniapolnapol[24] = "Jaka legenda jest związana z Warszawą?:\na. o smoku wawelskim \t                 -. o Popielu\n-. o Wandzie, co nie chciała Niemca\t d. o syrence \n";
    pytaniapolnapol[25] = "Kto ma łeb obdarty?:\n-. kto późno przychodzi  \t b. kto jest krótko ostrzyżony \nc. kto gra w karty \t         -. kto ma nos zadarty \n";
    pytaniapolnapol[26] = "Jak się pisze wyraz (rz/ż)(ó/u)raw? :\n-. ż, ó   \t -. rz, u  \nc. rz, u  \t d. ż, u \n";
    pytaniapolnapol[27] = "Co nie jest nazwą stylu pływackiego?:\na. rekin \t -. kraul \n-. żabka \t d. delfin \n";
    pytaniapolnapol[28] = "Która z tych małp jest największa?:\n-. orangutan \t -. kapucynka \nc. szympans \t d. goryl \n";
    pytaniapolnapol[29] = "Jaki jest numer straży pożarnej?:\n-. 999 \t b. 997 \nc. 998 \t -. 996 \n";
    pytaniapolnapol[30] = "W jakim mieście jest Wawel?:\n-. we Wrocławiu \t b. w Warszawie \n-. w Poznaniu \t         d. w Krakowie \n";
    pytaniapolnapol[31] = "Gdzie leży Arktyka?:\na. wokół bieguna południowego \t b. wokół bieguna północnego \n-. na równiku \t                 -. na Księżycu \n";
    pytaniapolnapol[32] = "Trzy z czterech nazw odnoszą się do tego samego oceanu. Która go nie dotyczy?:\na. Atlantyk \t -. Ocean Wielki \nc. Pacyfik \t -. Spokojny \n";
    pytaniapolnapol[33] = "Które ze świąt dzieli najmniejsza liczba dni od Andrzejek?:\na. Boże Narodzenie \t -. Wielkanoc \nc. Zaduszki \t         -. Święto Trzech Króli \n";
    pytaniapolnapol[34] = "Ile rodzonych córek miała macocha Kopciuszka w baśni braci Grimm?:\na. dwie \t b. trzy \n-. cztery \t -. pięć \n";
    pytaniapolnapol[35] = "Jak to dalej szło? „Opowiem ci bajkę, jak kot palił fajkę, a kocica papierosa… :\n-. kocięta zaś skręta \t b. w fifce, byle dalej nosa \nc. upaliła kawał nosa \t -. te koty zeszły z drogi cnoty \n";
    pytaniapolnapol[36] = "Czym Chińczycy tradycyjnie jadają potrawy z ryżu?:\na. łyżkami \t -. wykałaczkami \n-. widelcami \t d. pałeczkami \n";
    pytaniapolnapol[37] = "Ile miesięcy liczy kwartał?:\n-. 2 \t b. 3 \nc. 4 \t -. 5 \n";
    //srednie
    pytaniapolnapol[38] = "Kim z zawodu jest Frank Underwood – główny bohater serialu „House of Cards?:\n-. kierowcą rajdowym \t b. architektem \nc. politykiem \t         -. pokerzystą \n";
    pytaniapolnapol[39] = "Sążeń to antropometryczna miara długości równa rozpiętości:\na. pięt \t          b. ramion \n-. ramion cyrkla \t  -. zainteresowań \n";
    pytaniapolnapol[40] = "Co jest charakterystyczne w umaszczeniu doga niemieckiego zwanego arlekinem?:\na. czarna podpalana sierść \t  -. równo rozmieszczone pręgi \nc. czarne łaty na białym tle \t  -. jednolity złoty kolor \n";
    pytaniapolnapol[41] = "Dziko rośnie w Polsce i jest lianą:\n-. aktinidia smakowita \t  b. bluszcz pospolity \n-. malina właściwa \t  d. grab \n";
    pytaniapolnapol[42] = "W papieskim błogosławieństwie „Urbi et Orbi” - urbi znaczy miastu, a orbi?:\n-. wsi \t          b. światu \nc. słońcu \t  -. obieżyświatom \n";
    pytaniapolnapol[43] = "Słynne zwierzę senator za panowania cesarza Kaliguli to:\na. koń \t          -. wąż \n-. kozioł \t  d. kanarek \n";
    pytaniapolnapol[44] = "Który z półwyspów nie ma stałych rzek?:\na. Półwysep Skandynawski \t -. Półwysep Jutlandzki \n-. Półwysep Indyjski \t         d. Półwysep Arabski \n";
    pytaniapolnapol[45] = "Co ma łapawica?:\n-. brak zahamowań \t         b. „futerał” na kciuk \nc. stały potencjał infekcyjny \t -. składany miech \n";
    pytaniapolnapol[46] = "Jan Kochanowski po śmierci Zygmunta Augusta był zwolennikiem i uczestniczył w elekcji:\na. Augusta III Sasa \t -. Jana III Sobieskiego \n-. Jana II Kazimierza \t d. Henryka Walezego \n";
    pytaniapolnapol[47] = "Okulbaczyć to:\na. sprawić sobie binokle \t -. zaszczepić drzewko \n-. kontrolować okulistów \t d. osiodłać wierzchowca \n";
    pytaniapolnapol[48] = "Która z biblijnych postaci nosi przydomek Iskariota?:\n-. Mojżesz \t b. Judasz \nc. Noe \t         -. Abel \n";
    pytaniapolnapol[49] = "Których bierek w bierkach jest najwięcej?:\n-. wioseł \t -. bosaków \nc. trójzębów \t d. oszczepów \n";
    pytaniapolnapol[50] = "Wszystkie cztery brzmią tak samo, a jedno wygląda i brzmi inaczej odwołuje się do prawdy. Które?:\n-. banał \t -. komunał \nc. frazes \t d. truizm \n";
    pytaniapolnapol[51] = "Komiksowym 'dzieckiem' rysownika Boba Kane'a jest:\n-. Superman \t b. Batman \nc. Spider-Man \t -. Captain Ameryka \n";
    pytaniapolnapol[52] = "Likier maraskino produkuje się z maraski, czyli odmiany:\na. wiśni \t -. jabłoni \nc. figi \t -. gruszy \n";
    pytaniapolnapol[53] = "Który utwór Juliusza Słowackiego napisany jest prozą?:\na. „Godznia myśli” \t -. „W Szwajcarii” \nc. „Anhelli” \t         -. „Arabi” \n";
    pytaniapolnapol[54] = "Który ssak się nie spoci?:\n-. owca \t b. koń \n-. człowiek \t d. królik \n";
    pytaniapolnapol[55] = "Kogo dotyczy gamofobia?:\n-. kandydatów do pracy \t         b. przyszłych małżonków \nc. uczniów przed maturą \t -. graczy na giełdzie \n";
    pytaniapolnapol[56] = "Pad to najdłuższa rzeka:\n-. Hiszpanii \t b. Portugalii \n-. Grecji \t d. Włoch \n";
    pytaniapolnapol[57] = "Który smerf ma na ramieniu wytatuowane serce przebitą strzałą?:\n-. maruda \t b. osiłek \nc. ważniak \t -. ciamajda \n";
    pytaniapolnapol[58] = "Co tłusty krem potrafi zostawić na skórze?:\n-. koncert \t         -. sztukę \nc. operę mydlaną \t d. film \n";
    pytaniapolnapol[59] = "Za co przytulają hajs snugglersi?:\na. za przytulanie \t -. za lanie \nc. za kasę \t         -. za masę \n";
    pytaniapolnapol[60] = "Kogo uratowała Calineczka?:\n-. kreta \t b. jaskółkę \n-. pingwina \t d. żabę \n";
    pytaniapolnapol[61] = "Ile jest znaków zodiaku?:\na. 12  \t -. 15 \n-. 16 \t d. 10 \n";
    pytaniapolnapol[62] = "Do ilu punktów liczy się set w tenisie stołowym?:\na. 11  \t -. 25 \n-. 31 \t d. 21 \n";
    pytaniapolnapol[63] = "Jakie są najwyższe góry na świecie?:\n-. Tatry \t b. Himalaje \n-. Pireneje \t d. Alpy \n";
    pytaniapolnapol[64] = "Który z podanych instrumentów nie należy do grupy aerofonów?:\n-. obój \t -. tuba \nc. dudy \t d. żele \n";
    pytaniapolnapol[65] = "Wafel pieczony z delikatnego ciasta w specjalnych foremkach to:\n-. bajgiel \t b. andrut \nc. bakława \t -. beza \n";
    pytaniapolnapol[66] = "Które z określeń nie oznacza wysłannika?:\na. emisariusz \t -. kurier \n-. poseł \t d. ordyna \n";
    pytaniapolnapol[67] = "Tytułowa wataha z serialu wyreżyserowanego między innymi przez Kasię Adamik to:\n-. wilcza rodzina \t b. rosyjscy szpiedzy \nc. strażnicy graniczni \t -. uchodźcy ze Wschodu \n";
    //trunde
    pytaniapolnapol[68] = "Jaki instrument wykorzystał wędrowny szczurołap, który w XIII wieku miał wyprowadzić szkodniki z Hameln?:\n-. Bęben \t b. Flet \nc. Puzon \t -. Harfę \n";
    pytaniapolnapol[69] = "Konne tramwaje najwcześniej pojawiły się w Warszawie, a elektryczne?:\na. też w Warszawie \t -. w Bytomiu \n-. w Krakowie \t         d. we Wrocławiu \n";
    pytaniapolnapol[70] = "Wyrazy srebro i pieniądze brzmią tak samo, ale tylko:\n-. po niemiecku \t -. po rosyjsku \nc. po angielsku \t d. po francusku \n";
    pytaniapolnapol[71] = "Przykładem transhumancji jest:\na. wypędzanie owiec na hale \t -. klonowanie zwierząt \nc. mit o Minotaurze \t         -. galwanizowanie trupa \n";
    pytaniapolnapol[72] = "Symultanę rozgrywa się:\n-. w tenisie ziemnym \t b. w szachach \nc. w zapasach \t         -. w piłce nożnej \n";
    pytaniapolnapol[73] = "W 1937 r. w ramach pomocy generałowi Franco baskijską stolicę Guernicę prawie do cna zniszczyły bombardowania:\na. Luftwaffe \t                 -. Wojenno-Wozdusznych Sił \n-. United States Air Forces \t d. Royal Air Force \n";
    pytaniapolnapol[74] = "Na szlaku Orlich Gniazd natrafimy na liczne zamki obronne budowane na skalistych, wapiennych wzgórzach. Jednym z nich jest zamek:\na. w Olsztynie \t b. w Gnieźnie \n-. w Malborku \t -. w Łańcucie \n";
    pytaniapolnapol[75] = "„Jako to świadczymy, jako Anka zabiła Maciejowi wieprz i na wągrodzie mu nie dała paść” – to wyimek z tekstu:\n-. roty wojskowej \t b. roty sądowej \n-. roty ślubnej \t d. „Roty” Marii Konopnickiej \n";
    pytaniapolnapol[76] = "Kto jest mistrzem tego samego oręża, w jakim specjalizowała się mitologiczna Artemida?:\n-. Zorro \t b. Legolas \nc. Don Kichot \t -. Longinus Podbipięty \n";
    pytaniapolnapol[77] = "O ile oczu mniej ma mitologiczny Polifem od mitologicznego olbrzyma Argusa?:\na. o dziewięćdziesiąt dziewięć \t -. o dziewięćdziesiąt osiem \n-. o jedno \t                 d. o dwoje \n";
    pytaniapolnapol[78] = "Skąd pochodził Conan Barbarzyńca?:\n-. z Rivii \t -. z Oz \nc. z Mordoru \t d. z Cimmerii \n";
    pytaniapolnapol[79] = "Co według Leszka Kołakowskiego jest sklepieniem domu, w którym duch ludzki mieszka?:\n-. Rozum \t b. Bóg \n-. Miłość \t d. Czas \n";
    pytaniapolnapol[80] = "Odrażający drab z Kabaretu Starszych Panów dubeltówkę weźmie, wyjdzie i...:\n-. rach-ciach! \t b. buch, buch! \nc. z rur dwór \t -. bum w brzuch \n";
    pytaniapolnapol[81] = "Co widnieje na fladze Azorów?:\n-. pies \t b. psy \nc. jastrząb \t -. jastrzębie\n";
    pytaniapolnapol[82] = "Różańcową tajemnicą chwalebną nie jest...:\n-. Wniebowzięcie Matki Boskiej \t b. Zmartwychwstanie Jezusa \nc. Śmierć Jezusa na krzyżu \t -. Zesłanie Ducha Świętnego\n";
    pytaniapolnapol[83] = "Tylko jedno zawiera utarty zwrot. Które?:\n-. zebra pasi się na pasach \t b. droga jeży się trudnością \nc. licha lisi się sprytem \t -. jęki zajęczą się żałośnie\n";
    pytaniapolnapol[84] = "Choroba łokcia dotycząca mięśni zginaczy, na którą cierpią dentyści, księgowi i informatycy, to tak zwany łokieć:\na. golfisty \t -. kierowcy kabrioletu \nc. pływaka \t -. skoczka narciarskiego\n";
    pytaniapolnapol[86] = "Jaki jest kod pocztowy Kluczborku?:\na. 46-203 \t -. 43-370 \nc. 46-201 \t -. 40-200\n";
    pytaniapolnapol[87] = "Na akord można:\n-. spać \t b. pracować \n-. śpiewać \t d. podróżować\n";
    pytaniapolnapol[88] = "Co kaftan bezpieczeństwa ma znacznie dłuższe niż zwykły kaftan?:\n-. przód \t b. rękawy \nc. tył \t         -. kołnierz\n";
    pytaniapolnapol[89] = "Kto na igrzyskach olimpijskich w Pjongczangu nie mógł startować pod flagą własnego kraju?:\na. Kanadyjczycy \t -. Szwedzi \nc. Rosjanie \t         -. Chińczycy\n";
    pytaniapolnapol[90] = "Jak to dalej szło? „Góralu, czy ci nie żal…:\n-. „na wódkę wydawać szmal” \t         -. „podrzucać lasów i hal” \nc. „odchodzić od stron ojczystych” \t d. „religi zostawiać lesistych”\n";
    pytaniapolnapol[91] = "Co łączy rowerowa szprycha?:\na. obręcz z dętką \t -. dętkę z piastą \nc. piastę z obręczą \t -. obręcz z widelcem\n";
    pytaniapolnapol[92] = "Suspens to chwyt stosowany:\n-. w zapasach \t                 b. w grze na gitarze \n-. we wspinaczce klasycznej \t d. w filmach\n";
    pytaniapolnapol[93] = "Lew zabity przez Ramona Marcedera to:\na. Simba \t -. Tołstoj \nc. Trocki \t -. Mufasa\n";
    pytaniapolnapol[94] = "Który z wymienionych nie wystąpił w filmie fabularnym przed prezydenturą?:\na. Donald Trump \t -. Ronald Reagan \n-. Lech Kaczyński \t d. Valcav Havel\n";
    pytaniapolnapol[95] = "Jak nazywa się amerykańska baza wojskowa na Kubie?:\na. Santa Clara \t -. Bayamo \nc. Guantanamo \t -. Matanzas\n";
    pytaniapolnapol[96] = "Gdzie produkowany jest od 1835 roku włoski wermut Cinzano (rodzaj wina)?:\na. w Turynie \t         -. w Wenecji \nc. w Mediolanie \t -. we Florencji\n";
    pytaniapolnapol[97] = "Kto był malarzem króla Filipa IV Habsburga?:\na. Marcello Bacciarelli \t -. Jan van Eyck \nc. Diego Velázquez \t         -. Jacques-Louis David\n";
    pytaniapolnapol[98] = "Ile to jest 1111 razy 1111, jeśli 1 razy 1 to 1, a 11 razy 11 to 121?:\n-. 12321 \t b. 1 234 321 \nc. 111 111 111 \t -. 123 434 321\n";
    pytaniapolnapol[99] = "Symbol waluty euro to stylizowana grecka litera. Która?:\na. beta \t -. heta \n-. eta \t         d. epsilon\n";






    /* pytania_w_pliku.open("pytania.txt", ios::in);
     for (int i = 1; i <= 99; i++)
     {
         getline(pytania_w_pliku, pytania[i]);
     }
     pytania_w_pliku.close();

     odpowiedzi_w_pliku.open("odpowiedzi.txt", ios::in);
     for (int a = 1; a <= 99; a++)
     {
         getline(odpowiedzi_w_pliku, odpowiedzi_pobrane[a]);
     }
     odpowiedzi_w_pliku.close();

     string odpowiedzi_string;
     for (int i = 0; i < 100; i++)
     {
         odpowiedzi_string += odpowiedzi_pobrane[i]; //zamienia tablicę stringów na jednego stringa
     }
     strcpy_s(odpowiedzi, odpowiedzi_string.c_str()); //zamienia stringa na tablicę charów
     */

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "| $$$$$$$$$$ $$ $$   $$ $$$$$$$$ $$$$    $$ $$$$$$ $$$$$$$  $$$$$$ $$   $$ |\n";
    cout << "| $$$ $$ $$$ $$ $$   $$ $$    $$ $$ $$   $$ $$     $$   $$      $$ $$   $$ |\n";
    cout << "| $$  $$  $$ $$ $$   $$ $$    $$ $$  $$  $$ $$$$   $$$$$$$     $$  $$   $$ |\n";
    cout << "| $$  $$  $$ $$ $$   $$ $$    $$ $$   $$ $$ $$$$   $$$$       $$   $$$$$$$ |\n";
    cout << "| $$  $$  $$ $$ $$   $$ $$    $$ $$    $$$$ $$     $$ $$     $$      $$    |\n";
    cout << "| $$  $$  $$ $$ $$$$ $$ $$$$$$$$ $$     $$$ $$$$$$ $$  $$$  $$$$$$   $$    |\n";
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
MENU: cout << "Witaj w MILIONERACH!\n 1. Klasyczny tryb gry milionerzy\n 2. Tryb z dowolną iloscią pytan\n 3. Zasady \n 4. Wyniki\n";
    char a;
wybor:
    cout << "Wybierz opcje z menu\n";
    cin >> a;

    switch (a) {
    case '1':
        wyniki.open("wyniki.txt", ios::out | ios::app); //otwarcie pliku tekstowego z wynikami
        cout << "Proszę podać nick: ";
        cin >> nick;
        system("cls");
        //pierwsze pytanie
    ponowne_losowanie_pierwszego:  index = rand() % 37 + 1;
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "Pytanie 1:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł <- |\n";
        cout << " =====================\n";
        char odp;
    powrot_do_pierwszego:
        cin >> odp;
        odp = char(tolower(odp));

        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 500zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == '0') {
            system("cls");
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 0 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 0 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_pierwszego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_pierwszego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_pierwszego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_pierwszym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_pierwszego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 1:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda: 500zł!\n";
            else
            {
                goto porazka_w_pierwszym;
            }
        }
        else {
        porazka_w_pierwszym:
            cout << "Błędna odpowiedź. Wygrywasz 0 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 0 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //drugie pytanie
    ponowne_losowanie_drugiego:  index = rand() % 37 + 1;
        cout << "Pytanie 2:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł <- |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_drugiego:  cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda gwarantowana: 1000zł.\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 500 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 500 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_drugiego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_drugiego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_drugiego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_drugim;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_drugiego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 2:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda: 1000zł!\n";
            else
            {
                goto porazka_w_drugim;
            }
        }
        else {
        porazka_w_drugim: cout << "Błędna odpowiedź. Wygrywasz 0 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 0 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //trzecie pytanie
    ponowne_losowanie_trzeciego:  index = rand() % 30 + 38;
        cout << "Pytanie 3:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł <- |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";;
    powrot_do_trzeciego: cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 2 000zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 1 000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 1 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_trzeciego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_trzeciego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_trzeciego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_trzecim;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_trzeciego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 3:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda: 2000zł!\n";
            else
            {
                goto porazka_w_trzecim;
            }
        }
        else {
        porazka_w_trzecim:  cout << "Błędna odpowiedź. Wygrywasz gwarantowane od drugiego pytania 1 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl;
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 1 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //czwarte pytanie
    ponowne_losowanie_czwartego:  index = rand() % 30 + 38;
        cout << "Pytanie 4:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł <- |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_czwartego:  cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 5000zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 2000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 2 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_czwartego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \n Nowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_czwartego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_czwartego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_czwartym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_czwartego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 4:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda: 5 000zł!\n";
            else
            {
                goto porazka_w_czwartym;
            }
        }
        else {
        porazka_w_czwartym: cout << "Błędna odpowiedź. Wygrywasz gwarantowane od drugiego pytania 1 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 1 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //piate pytanie
    ponowne_losowanie_piatego:  index = rand() % 30 + 38;
        cout << "Pytanie 5:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł <- |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_piatego:  cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 10 000zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 5 000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 5 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_piatego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \n Nowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_piatego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_piatego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_piatym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_piatego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 5:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda: 10 000zł!\n";
            else
            {
                goto porazka_w_piatym;
            }
        }
        else {
        porazka_w_piatym: cout << "Błędna odpowiedź. Wygrywasz gwarantowane od drugiego pytania 1 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 1 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //szoste pytanie
    ponowne_losowanie_szostego:  index = rand() % 30 + 38;
        cout << "Pytanie 6:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł <- |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_szostego:  cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 20 000zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 10 000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 10 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_szostego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_szostego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_szostego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_szostym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_szostego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 6:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda: 20 000zł!\n";
            else
            {
                goto porazka_w_szostym;
            }
        }
        else {
        porazka_w_szostym: cout << "Błędna odpowiedź. Wygrywasz gwarantowane od drugiego pytania 1 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 1 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //siodme pytanie
    ponowne_losowanie_siodmego:  index = rand() % 30 + 38;
        cout << "Pytanie 7:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł <- |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_siodmego:   cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 40 000zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 20 000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 20 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_siodmego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania!\n Nowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_siodmego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_siodmego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_siodmym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_siodmego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 7:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda gwarantowana: 40 000zł!\n";
            else
            {
                goto porazka_w_siodmym;
            }
        }
        else {
        porazka_w_siodmym: cout << "Błędna odpowiedź. Wygrywasz gwarantowane od drugiego pytania 1 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 1 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //osme pytanie
    ponowne_losowanie_osmego:   index = rand() % 32 + 68;
        cout << "Pytanie 8:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł <- |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_osmego:   cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 75 000zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 40 000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 40 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_osmego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_osmego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_osmego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_osmym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_osmego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 8:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda : 75 000zł!\n";
            else
            {
                goto porazka_w_osmym;
            }
        }
        else {
        porazka_w_osmym: cout << "Błędna odpowiedź. Wygrywasz gwarantowane od siódmego pytania 40 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 40 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //dziewiate pytanie
    ponowne_losowanie_dziewiatego: index = rand() % 32 + 68;
        cout << "Pytanie 9:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł <- |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_dziewiatego:   cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 125 000zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 75 000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 75 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_dziewiatego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_dziewiatego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_dziewiatego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_dziewiatym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_dziewiatego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 9:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda : 125 000zł!\n";
            else
            {
                goto porazka_w_dziewiatym;
            }
        }
        else {
        porazka_w_dziewiatym: cout << "Błędna odpowiedź. Wygrywasz gwarantowane od siódmego pytania 40 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 40 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //dziesiate pytanie
    ponowne_losowanie_dziesiatego:  index = rand() % 32 + 68;
        cout << "Pytanie 10:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł <- |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_dziesiatego:  cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 250 000zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 125 000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 125 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_dziesiatego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_dziesiatego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_dziesiatego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_dziesiatym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_dziesiatego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 10:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda : 250 000zł!\n";
            else
            {
                goto porazka_w_dziesiatym;
            }
        }
        else {
        porazka_w_dziesiatym: cout << "Błędna odpowiedź. Wygrywasz gwarantowane od siódmego pytania 40 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 40 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //jedenaste pytanie
    ponowne_losowanie_jedynastego:  index = rand() % 32 + 68;
        cout << "Pytanie 11:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł    |\n";
        cout << "| 11:   500.000 zł <- |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_jedynastego:   cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            cout << "Dobrze! Obecna nagroda: 500 000zł\n";
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 250 000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 250 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_jedynastego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_jedynastego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_jedynastego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                cout << "To poprawna odpowiedź!\n";
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedź!\n";
                }
                else
                {
                    goto porazka_w_jedynastym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_jedynastego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 11:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedź! Obecna nagroda : 500 000zł!\n";
            else
            {
                goto porazka_w_jedynastym;
            }
        }
        else {
        porazka_w_jedynastym: cout << "Błędna odpowiedź. Wygrywasz gwarantowane od siódmego pytania 40 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 40 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        //dwunaste pytanie
    ponowne_losowanie_dwunastego: index = rand() % 32 + 68;
        cout << "Pytanie 12:\n" << pytania[index];
        cout << " =====================\n";
        cout << "| 12: 1.000.000 zł <- |\n";
        cout << "| 11:   500.000 zł    |\n";
        cout << "| 10:   250.000 zł    |\n";
        cout << "|  9:   100.000 zł    |\n";
        cout << "|  8:    75.000 zł    |\n";
        cout << "|  7:   *40.000 zł    |\n";
        cout << "|  6:    20.000 zł    |\n";
        cout << "|  5:    10.000 zł    |\n";
        cout << "|  4:     5.000 zł    |\n";
        cout << "|  3:     2.000 zł    |\n";
        cout << "|  2:    *1.000 zł    |\n";
        cout << "|  1:       500 zł    |\n";
        cout << " =====================\n";
    powrot_do_dwunastego:  cin >> odp;
        odp = char(tolower(odp));
        if (odp == odpowiedzi[index]) {
            system("cls");
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
            cout << "GRATULACJE!!!\n";
            cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
            cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
            cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
            cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
            cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
            cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
            cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            licznikDobrychOdpowiedzi++;
        }
        else if (odp == 0) {
            cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 500 000 zł!";
            wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
            wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
            wyniki << "Wygrana kwota: 500 000 zł" << endl;
            wyniki << "-------------------" << endl;
            wyniki.close();
            break;
        }
        else if (odp == '7')
        {
            if (zamianapytania == 1)
            {
                cout << "Nie posiadasz już zamiany pytania. Proszę podać odpowiedź:";
                goto powrot_do_dwunastego;
            }
            system("cls");
            cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
            zamianapytania++;
            goto ponowne_losowanie_dwunastego;
        }
        else if (odp == '8')
        {
            if (podwojnaodpowiedz == 1)
            {
                cout << "Nie posiadasz już podwójnej odpowiedzi. Proszę podać odpowiedź:";
                goto powrot_do_dwunastego;
            }
            podwojnaodpowiedz++;
            cout << "Wybrano podwójną odpowiedź! \nProszę podać odpowiedź(masz jeszcze dwie szanse):";
            cin >> odp;
            if (odp == odpowiedzi[index])
            {
                system("cls");
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
                cout << "GRATULACJE!!!\n";
                cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else
            {
                cout << "Niestety, to nie jest poprawna odpowiedź.\nProszę podać odpowiedź(masz jeszcze jedną szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
                    cout << "GRATULACJE!!!\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                }
                else
                {
                    goto porazka_w_dwunastym;
                }
            }
        }
        else if (odp == '9')
        {
            if (polnapol == 1)
            {
                cout << "Nie posiadasz już pół na pół. Proszę podać odpowiedź:";
                goto powrot_do_dwunastego;
            }
            polnapol++;
            system("cls");
            cout << "Wybrano pół na pół! Wykluczam dwie błędne odpowiedzi:\n";
            cout << "Pytanie 12:\n" << pytaniapolnapol[index];
            cin >> odp;
            if (odp == odpowiedzi[index]) {
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
                cout << "GRATULACJE!!!\n";
                cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else
            {
                goto porazka_w_dwunastym;
            }
        }
        else {
        porazka_w_dwunastym: cout << "Błędna odpowiedź. Wygrywasz gwarantowane od siódmego pytania 40 000 zł! KONIEC GRY!";
            licznikZlychOdpowiedzi++;
            if (licznikZlychOdpowiedzi == 1) {
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilość prawidłowych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 40 000 zł" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
        }
        break;
    case '2':
        cout << "Ile chcesz mieć pytań?:";
        int iloscPytan;
        cin >> iloscPytan;
        for (int i = 0; i < iloscPytan; i++) {
            index = rand() % 99 + 1;
            cout << pytania[index];
            char odp;
            cin >> odp;
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze!\n";
                licznikDobrychOdpowiedzi++;
                if (licznikDobrychOdpowiedzi == iloscPytan) {
                    system("cls");
                    cout << "Koniec pytan. KONIEC GRY!";
                    break;
                }
            }
            else {
                licznikZlychOdpowiedzi++;
                system("cls");
                cout << "Błędna odpowiedź. To twoja " << licznikZlychOdpowiedzi << " zła odpowiedź\n";

                if (licznikZlychOdpowiedzi == 3) {
                    system("cls");
                    cout << "KONIEC GRY! Popełniłeś 3 błędy.";
                    break;
                }
            }
        }
        break;
    case '3': //wyświetlenie zasad
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

        {
            system("cls");
            cout << "===============================================================\n";
            cout << "INSTRUKCJA:\nDo wyboru masz dwa tryby gry:\n1) Klasyczni milionerzy \n2) Losowe pytania" << endl;
            cout << "W trybie klasycznym, rozgrywka wyglada jak lekko zmodyfikowana gra w milionerów.\nMamy 12 pytań, 3 koła ratunkowe, kwoty gwaranowane oraz koniec gry w razie błędnej opdowiedzi.\nW każdej chwili można wyjść z gry i zabrać pieniądze, wpisując 0 zamiast literki z odpowiedzią.\nJeśli chcesz użyć kół ratunkowych, wpisz 7/8/9, aby użyć odpowiednio-zamiany pytania/podwójna odpowiedź/pół na pół. \nW tym trybie wyniki są zapisywane i można je potem odczytać" << endl;
            cout << "W trybie losowym, to użytkownik decyduje na ile pytań chce odpowiedzieć, a następnie ma 3 życia. W tym trybie nie ma kół ratunkowych ani nagród.\nW tym trybie wyniki nie są zapisywane." << endl;
            cout << "Aby sprawdzić wyniki z trybu klasycznego, wpisz w menu gry 4.\n";
            cout << "==============================================================\n";
            goto MENU;
            break;
        }
    case '4': //wyświetlenie wyników
    {
        cout << "WYNIKI:" << endl;
        wyniki.open("wyniki.txt", ios::in);
        if (wyniki.good() == false) {
            cout << "Taki plik nie istnieje! Zagraj w trybie klasycznym minimum raz, aby mieć wyniki!";
            goto MENU;
        }
        else {
            string linia;
            int nr_linii = 1;
            while (getline(wyniki, linia))
            {
                cout << linia << endl;
            }
            wyniki.close();
            goto MENU;
            break;
        }

    }
    default:
        cout << "Znak spoza zakresu\n";
        goto wybor;
    }

}
