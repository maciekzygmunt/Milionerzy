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

    pytania[1] = "Który z tych u³amków to u³amek niew³aœciwy?:\na. 3/4\tb. 0,3\nc. 4/3\td. 0,33\n";
    odpowiedzi[1] = 'c';
    pytania[2] = "Twarz i poca³unek to?:\na. morda\tb. ca³us\nc. cmok \td. buziak\n";
    odpowiedzi[2] = 'd';
    pytania[3] = "Do czego s³u¿y krawcowej blaszka na palec?:\na. do ochrony palca\t         b. do prucia fastryg\nc. do obrzucania dziurek\t d. do nawlekania igie³\n";
    odpowiedzi[3] = 'd';
    pytania[4] = "Wska¿ b³¹d.:\na. wymyœliæ coœ naprêdce\t b. schodziæ na manowce\nc. nadwerê¿yæ plecy\t         d. poddaæ coœ w w¹tpliwoœæ\n";
    odpowiedzi[4] = 'd';
    pytania[5] = "K³óciæ siê z kimœ, robiæ mu na z³oœliwoœci to pójœæ z nim:\na. w sukurs\t b. jak w dym\nc. w konkury\t d. na udry\n";
    odpowiedzi[5] = 'd';
    pytania[6] = "Co ma lodowiec?:\na. ga³y\t b. jêzor\nc. girê\t d. ka³dun\n";
    odpowiedzi[6] = 'b';
    pytania[7] = "Polskie ruskie pierogi nadziewane s¹?:\na. bia³¹ i czerwon¹ kapust¹\t b. bia³a i czerwon¹ fasol¹\nc. bia³ym i czerwonym miêsem\t d. ziemniakami i serem\n";
    odpowiedzi[7] = 'd';
    pytania[8] = "W jakim mieœcie odbywa³y siê s³ynne spotkania naukowo-literackie zwane obiadami czwartkowymi?:\na. w GnieŸnie\t b. w Pu³awach\nc. w Warszawie\t d. w Krakowie\n";
    odpowiedzi[8] = 'c';
    pytania[9] = "Kto napisa³ „Would you know my name if I saw you in heaven”I to œpiewa z gitar¹?:\na. Soyka\t b. Phil Collins\nc. Eric Clapton\t d. Sting\n";
    odpowiedzi[9] = 'c';
    pytania[10] = "Czego mog³a u¿yczyæ Dafne po przemianie?:\na. laski wanilii\t b. listka bobkowego\nc. kryszta³u soli\t d. kory cynamonu\n";
    odpowiedzi[10] = 'b';
    pytania[11] = "Na krechê:\na. powo³ywa³ siê T.Mazowiecki\t b. skacze temperatura\nc. zje¿d¿aj¹ narciarze\t         d. czeka³ przys³owiowy Matysek\n";
    odpowiedzi[11] = 'c';
    pytania[12] = "Zagalopowaæ siê to posun¹æ siê:\na. w latach\t b. nieco na koniu\nc. za daleko\t d. o w³os\n";
    odpowiedzi[12] = 'c';
    pytania[13] = "Nie ma ¿adnych pañstw oœciennych:\na. Polska\t b. Portugalia\nc. Serbia\t d. Islandia\n";
    odpowiedzi[13] = 'd';
    pytania[14] = "Który instrument stroi muzyk?:\na. tamburyn\t b. kocio³\nc. okarynê\t d. czynele\n";
    odpowiedzi[14] = 'b';
    pytania[15] = "Z gry na jakim instrumencie s³ynie Czes³aw Mozil?:\na. na kornecie\t b. na akordeonie\nc. na djembe\t d. na saksofonie\n";
    odpowiedzi[15] = 'b';
    pytania[16] = "Co ukoi nerwy i zast¹pi cytrynê?:\na. melisa lekarska\t b. miêta pieprzowa\nc. jaskó³cze ziele\t d. ziele angielskie \n";
    odpowiedzi[16] = 'a';
    pytania[17] = "Co kroimy w piórka?:\na. cebulê\t b. natkê pietruszki\nc. buraki\t d. seler naciowy \n";
    odpowiedzi[17] = 'a';
    pytania[18] = "Jaki kolor ma dodawany do gum do ¿ucia, pasta do zêbów, cukru pudru i wielu innych produktów dwutlenku tytanu?:\na. zielony\t b. czerwony\nc. czarny\t d. bia³y \n";
    odpowiedzi[18] = 'd';
    pytania[19] = "Wszystkie œmieci rozk³adaj¹ siê kilkaset lat, ale najd³u¿ej:\na. pampers\t         b. plastikowa torebka\nc. ¿y³ka wêdkarska\t d. aluminiowa puszka \n";
    odpowiedzi[19] = 'c';
    pytania[20] = "Który z indeksów reprezentuje Gie³dê Papierów Wartoœciowych w Warszawie?:\na. DAX\t b. NASDAQ\nc. WIG\t d. Dow Jones \n";
    odpowiedzi[20] = 'c';
    pytania[21] = "Politycy ³¹cz¹ w popularna piramidkê:\na. mandaty poselskie\t b. proletariuszy wszystkich krajów\nc. palce d³oni\t         d. punkty wyst¹pienia \n";
    odpowiedzi[21] = 'c';
    pytania[22] = "Jaka czêœæ mowy odpowiada na pytania: kto, co?:\na. przymiotnik\t b. czasownik\nc. rzeczownik\t d. przys³ówek \n";
    odpowiedzi[22] = 'c';
    pytania[23] = "Co powstanie z wody, gdy j¹ zamrozimy?:\na. para\t b. chmura\nc. lód\t d. mleko \n";
    odpowiedzi[23] = 'c';
    pytania[24] = "Jaka legenda jest zwi¹zana z Warszaw¹?:\na. o smoku wawelskim \t                 b. o Popielu\nc. o Wandzie, co nie chcia³a Niemca\t d. o syrence \n";
    odpowiedzi[24] = 'd';
    pytania[25] = "Kto ma ³eb obdarty?:\na. kto póŸno przychodzi  \t b. kto jest krótko ostrzy¿ony \nc. kto gra w karty \t         d. kto ma nos zadarty \n";
    odpowiedzi[25] = 'c';
    pytania[26] = "Jak siê pisze wyraz (rz/¿)(ó/u)raw? :\na. ¿, ó   \t b. rz, u  \nc. rz, u  \t d. ¿, u \n";
    odpowiedzi[26] = 'd';
    pytania[27] = "Co nie jest nazw¹ stylu p³ywackiego?:\na. rekin \t b. kraul \nc. ¿abka \t d. delfin \n";
    odpowiedzi[27] = 'a';
    pytania[28] = "Która z tych ma³p jest najwiêksza?:\na. orangutan \t b. kapucynka \nc. szympans \t d. goryl \n";
    odpowiedzi[28] = 'd';
    pytania[29] = "Jaki jest numer stra¿y po¿arnej?:\na. 999 \t b. 997 \nc. 998 \t d. 996 \n";
    odpowiedzi[29] = 'c';
    pytania[30] = "W jakim mieœcie jest Wawel?:\na. we Wroc³awiu \t b. w Warszawie \nc. w Poznaniu \t         d. w Krakowie \n";
    odpowiedzi[30] = 'd';
    pytania[31] = "Gdzie le¿y Arktyka?:\na. wokó³ bieguna po³udniowego \t b. wokó³ bieguna pó³nocnego \nc. na równiku \t                 d. na Ksiê¿ycu \n";
    odpowiedzi[31] = 'b';
    pytania[32] = "Trzy z czterech nazw odnosz¹ siê do tego samego oceanu. Która go nie dotyczy?:\na. Atlantyk \t b. Ocean Wielki \nc. Pacyfik \t d. Spokojny \n";
    odpowiedzi[32] = 'a';
    pytania[33] = "Które ze œwi¹t dzieli najmniejsza liczba dni od Andrzejek?:\na. Bo¿e Narodzenie \t b. Wielkanoc \nc. Zaduszki \t         d. Œwiêto Trzech Króli \n";
    odpowiedzi[33] = 'a';
    pytania[34] = "Ile rodzonych córek mia³a macocha Kopciuszka w baœni braci Grimm?:\na. dwie \t b. trzy \nc. cztery \t d. piêæ \n";
    odpowiedzi[34] = 'a';
    pytania[35] = "Jak to dalej sz³o? „Opowiem ci bajkê, jak kot pali³ fajkê, a kocica papierosa… :\na. kociêta zaœ skrêta \t b. w fifce, byle dalej nosa \nc. upali³a kawa³ nosa \t d. te koty zesz³y z drogi cnoty \n";
    odpowiedzi[35] = 'c';
    pytania[36] = "Czym Chiñczycy tradycyjnie jadaj¹ potrawy z ry¿u?:\na. ³y¿kami \t b. wyka³aczkami \nc. widelcami \t d. pa³eczkami \n";
    odpowiedzi[36] = 'd';
    pytania[37] = "Ile miesiêcy liczy kwarta³?:\na. 2 \t b. 3 \nc. 4 \t d. 5 \n";
    odpowiedzi[37] = 'b';
    //srednie
    pytania[38] = "Kim z zawodu jest Frank Underwood – g³ówny bohater serialu „House of Cards?:\na. kierowc¹ rajdowym \t b. architektem \nc. politykiem \t         d. pokerzyst¹ \n";
    odpowiedzi[38] = 'c';
    pytania[39] = "S¹¿eñ to antropometryczna miara d³ugoœci równa rozpiêtoœci:\na. piêt \t          b. ramion \nc. ramion cyrkla \t  d. zainteresowañ \n";
    odpowiedzi[39] = 'b';
    pytania[40] = "Co jest charakterystyczne w umaszczeniu doga niemieckiego zwanego arlekinem?:\na. czarna podpalana sierœæ \t  b. równo rozmieszczone prêgi \nc. czarne ³aty na bia³ym tle \t  d. jednolity z³oty kolor \n";
    odpowiedzi[40] = 'c';
    pytania[41] = "Dziko roœnie w Polsce i jest lian¹:\na. aktinidia smakowita \t  b. bluszcz pospolity \nc. malina w³aœciwa \t  d. grab \n";
    odpowiedzi[41] = 'b';
    pytania[42] = "W papieskim b³ogos³awieñstwie „Urbi et Orbi” - urbi znaczy miastu, a orbi?:\na. wsi \t          b. œwiatu \nc. s³oñcu \t  d. obie¿yœwiatom \n";
    odpowiedzi[42] = 'b';
    pytania[43] = "S³ynne zwierzê senator za panowania cesarza Kaliguli to:\na. koñ \t          b. w¹¿ \nc. kozio³ \t  d. kanarek \n";
    odpowiedzi[43] = 'a';
    pytania[44] = "Który z pó³wyspów nie ma sta³ych rzek?:\na. Pó³wysep Skandynawski \t b. Pó³wysep Jutlandzki \nc. Pó³wysep Indyjski \t         d. Pó³wysep Arabski \n";
    odpowiedzi[44] = 'd';
    pytania[45] = "Co ma ³apawica?:\na. brak zahamowañ \t         b. „futera³” na kciuk \nc. sta³y potencja³ infekcyjny \t d. sk³adany miech \n";
    odpowiedzi[45] = 'b';
    pytania[46] = "Jan Kochanowski po œmierci Zygmunta Augusta by³ zwolennikiem i uczestniczy³ w elekcji:\na. Augusta III Sasa \t b. Jana III Sobieskiego \nc. Jana II Kazimierza \t d. Henryka Walezego \n";
    odpowiedzi[46] = 'd';
    pytania[47] = "Okulbaczyæ to:\na. sprawiæ sobie binokle \t b. zaszczepiæ drzewko \nc. kontrolowaæ okulistów \t d. osiod³aæ wierzchowca \n";
    odpowiedzi[47] = 'd';
    pytania[48] = "Która z biblijnych postaci nosi przydomek Iskariota?:\na. Moj¿esz \t b. Judasz \nc. Noe \t         d. Abel \n";
    odpowiedzi[48] = 'b';
    pytania[49] = "Których bierek w bierkach jest najwiêcej?:\na. wiose³ \t b. bosaków \nc. trójzêbów \t d. oszczepów \n";
    odpowiedzi[49] = 'd';
    pytania[50] = "Wszystkie cztery brzmi¹ tak samo, a jedno wygl¹da i brzmi inaczej odwo³uje siê do prawdy. Które?:\na. bana³ \t b. komuna³ \nc. frazes \t d. truizm \n";
    odpowiedzi[50] = 'd';
    pytania[51] = "Komiksowym 'dzieckiem' rysownika Boba Kane'a jest:\na. Superman \t b. Batman \nc. Spider-Man \t d. Captain Ameryka \n";
    odpowiedzi[51] = 'b';
    pytania[52] = "Likier maraskino produkuje siê z maraski, czyli odmiany:\na. wiœni \t b. jab³oni \nc. figi \t d. gruszy \n";
    odpowiedzi[52] = 'a';
    pytania[53] = "Który utwór Juliusza S³owackiego napisany jest proz¹?:\na. „Godznia myœli” \t b. „W Szwajcarii” \nc. „Anhelli” \t         d. „Arabi” \n";
    odpowiedzi[53] = 'c';
    pytania[54] = "Który ssak siê nie spoci?:\na. owca \t b. koñ \nc. cz³owiek \t d. królik \n";
    odpowiedzi[54] = 'd';
    pytania[55] = "Kogo dotyczy gamofobia?:\na. kandydatów do pracy \t         b. przysz³ych ma³¿onków \nc. uczniów przed matur¹ \t d. graczy na gie³dzie \n";
    odpowiedzi[55] = 'b';
    pytania[56] = "Pad to najd³u¿sza rzeka:\na. Hiszpanii \t b. Portugalii \nc. Grecji \t d. W³och \n";
    odpowiedzi[56] = 'd';
    pytania[57] = "Który smerf na ramieniu wytatuowane serce przebit¹ strza³¹?:\na. maruda \t b. osi³ek \nc. wa¿niak \t d. ciamajda \n";
    odpowiedzi[57] = 'b';
    pytania[58] = "Co t³usty krem potrafi zostawiæ na skórze?:\na. koncert \t         b. sztukê \nc. operê mydlan¹ \t d. film \n";
    odpowiedzi[58] = 'd';
    pytania[59] = "Za co przytulaj¹ hajs snugglersi?:\na. za przytulanie \t b. za lanie \nc. za kasê \t         d. za masê \n";
    odpowiedzi[59] = 'a';
    pytania[60] = "Kogo uratowa³a Calineczka?:\na. kreta \t b. jaskó³kê \nc. pingwina \t d. ¿abê \n";
    odpowiedzi[60] = 'b';
    pytania[61] = "Ile jest znaków zodiaku?:\na. 12  \t b. 15 \nc. 16 \t d. 10 \n";
    odpowiedzi[61] = 'a';
    pytania[62] = "Do ilu punktów liczy siê set w tenisie sto³owym?:\na. 21  \t b. 25 \nc. 31 \t d. 20 \n";
    odpowiedzi[62] = 'a';
    pytania[63] = "Jakie s¹ najwy¿sze góry na œwiecie?:\na. Tatry \t b. Himalaje \nc. Pireneje \t d. Alpy \n";
    odpowiedzi[63] = 'b';
    pytania[64] = "Który z podanych instrumentów nie nale¿y do grupy aerofonów?:\na. obój \t b. tuba \nc. dudy \t d. ¿ele \n";
    odpowiedzi[64] = 'd';
    pytania[65] = "Wafel pieczony z delikatnego ciasta w specjalnych foremkach to:\na. bajgiel \t b. andrut \nc. bak³awa \t d. beza \n";
    odpowiedzi[65] = 'b';
    pytania[66] = "Które z okreœleñ nie oznacza wys³annika?:\na. emisariusz \t b. kurier \nc. pose³ \t d. ordyna \n";
    odpowiedzi[66] = 'd';
    pytania[67] = "Tytu³owa wataha z serialu wyre¿yserowanego miêdzy innymi przez Kasiê Adamik to:\na. wilcza rodzina \t b. rosyjscy szpiedzy \nc. stra¿nicy graniczni \t d. uchodŸcy ze Wschodu \n";
    odpowiedzi[67] = 'c';
    //trunde
    pytania[68] = "Jaki instrument wykorzysta³ wêdrowny szczuro³ap, który w XIII wieku mia³ wyprowadziæ szkodniki z Hameln?:\na. Bêben \t b. Flet \nc. Puzon \t d. Harfê \n";
    odpowiedzi[68] = 'b';
    pytania[69] = "Konne tramwaje najwczeœniej pojawi³y siê w Warszawie, a elektryczne?:\na. te¿ w Warszawie \t b. w Bytomiu \nc. w Krakowie \t         d. we Wroc³awiu \n";
    odpowiedzi[69] = 'd';
    pytania[70] = "Wyrazy srebro i pieni¹dze brzmi¹ tak samo, ale tylko:\na. po niemiecku \t b. po rosyjsku \nc. po angielsku \t d. po francusku \n";
    odpowiedzi[70] = 'd';
    pytania[71] = "Przyk³adem transhumancji jest:\na. wypêdzanie owiec na hale \t b. klonowanie zwierz¹t \nc. mit o Minotaurze \t         d. galwanizowanie trupa \n";
    odpowiedzi[71] = 'a';
    pytania[72] = "Symultanê rozgrywa siê:\na. w tenisie ziemnym \t b. w szachach \nc. w zapasach \t         d. w pi³ce no¿nej \n";
    odpowiedzi[72] = 'b';
    pytania[73] = "W 1937 r. w ramach pomocy genera³owi Franco baskijsk¹ stolicê Guernicê prawie do cna zniszczy³y bombardowania:\na. Luftwaffe \t                 b. Wojenno-Wozdusznych Si³ \nc. United States Air Forces \t d. Royal Air Force \n";
    odpowiedzi[73] = 'a';
    pytania[74] = "Na szlaku Orlich Gniazd natrafimy na liczne zamki obronne budowane na skalistych, wapiennych wzgórzach. Jednym z nich jest zamek:\na. w Olsztynie \t b. w GnieŸnie \nc. w Malborku \t d. w £añcucie \n";
    odpowiedzi[74] = 'a';
    pytania[75] = "„Jako to œwiadczymy, jako Anka zabi³a Maciejowi wieprz i na w¹grodzie mu nie da³a paœæ” – to wyimek z tekstu:\na. roty wojskowej \t b. roty s¹dowej \nc. roty œlubnej \t d. „Roty” Marii Konopnickiej \n";
    odpowiedzi[75] = 'b';
    pytania[76] = "Kto jest mistrzem tego samego orê¿a, w jakim specjalizowa³a siê mitologiczna Artemida?:\na. Zorro \t b. Legolas \nc. Don Kichot \t d. Longinus Podbipiêty \n";
    odpowiedzi[76] = 'b';
    pytania[77] = "O ile oczu mniej ma mitologiczny Polifem od mitologicznego olbrzyma Argusa?:\na. o dziewiêædziesi¹t dziewiêæ \t b. o dziewiêædziesi¹t osiem \nc. o jedno \t                 d. o dwoje \n";
    odpowiedzi[77] = 'a';
    pytania[78] = "Sk¹d pochodzi³ Conan Barbarzyñca?:\na. z Rivii \t b. z Oz \nc. z Mordoru \t d. z Cimmerii \n";
    odpowiedzi[78] = 'd';
    pytania[79] = "Co wed³ug Leszka Ko³akowskiego jest sklepieniem domu, w którym duch ludzki mieszka?:\na. Rozum \t b. Bóg \nc. Mi³oœæ \t d. Czas \n";
    odpowiedzi[79] = 'd';
    pytania[80] = "Odra¿aj¹cy drab z Kabaretu Starszych Panów dubeltówkê weŸmie, wyjdzie i...:\na. rach-ciach! \t b. buch, buch! \nc. z rur dwór \t d. bum w brzuch \n";
    odpowiedzi[80] = 'b';
    pytania[81] = "Co widnieje na fladze Azorów?:\na. pies \t b. psy \nc. jastrz¹b \t d. jastrzêbie\n";
    odpowiedzi[81] = 'c';
    pytania[82] = "Ró¿añcow¹ tajemnic¹ chwalebn¹ nie jest...:\na. Wniebowziêcie Matki Boskiej \t b. Zmartwychwstanie Jezusa \nc. Œmieræ Jezusa na krzy¿u \t d. Zes³anie Ducha Œwiêtnego\n";
    odpowiedzi[82] = 'c';
    pytania[83] = "Tylko jedno zawiera utarty zwrot. Które?:\na. zebra pasi siê na pasach \t b. droga je¿y siê trudnoœci¹ \nc. licha lisi siê sprytem \t d. jêki zajêcz¹ siê ¿a³oœnie\n";
    odpowiedzi[83] = 'b';
    pytania[84] = "Choroba ³okcia dotycz¹ca miêœni zginaczy, na któr¹ cierpi¹ dentyœci, ksiêgowi i informatycy, to tak zwany ³okieæ:\na. golfisty \t b. kierowcy kabrioletu \nc. p³ywaka \t d. skoczka narciarskiego\n";
    odpowiedzi[84] = 'a';
    pytania[85] = "Gdzie w 16 miesiêcy w³ókniarkê zmieniono w kosmonautkê?:\na. w Chinach \t b. w USA \nc. w ZSRR \t d. w Rumunii\n";
    odpowiedzi[85] = 'c';
    pytania[86] = "Jaki jest kod pocztowy Kluczborku?:\na. 46-203 \t b. 43-370 \nc. 46-201 \t d. 40-200\n";
    odpowiedzi[86] = 'a';
    pytania[87] = "Na akord mo¿na:\na. spaæ \t b. pracowaæ \nc. œpiewaæ \t d. podró¿owaæ\n";
    odpowiedzi[87] = 'b';
    pytania[88] = "Co kaftan bezpieczeñstwa ma znacznie d³u¿sze ni¿ zwyk³y kaftan?:\na. przód \t b. rêkawy \nc. ty³ \t         d. ko³nierz\n";
    odpowiedzi[88] = 'b';
    pytania[89] = "Kto na igrzyskach olimpijskich w Pjongczangu nie móg³ startowaæ pod flag¹ w³asnego kraju?:\na. Kanadyjczycy \t b. Szwedzi \nc. Rosjanie \t         d. Chiñczycy\n";
    odpowiedzi[89] = 'c';
    pytania[90] = "Jak to dalej sz³o? „Góralu, czy ci nie ¿al…:\na. „na wódkê wydawaæ szmal” \t         b. „podrzucaæ lasów i hal” \nc. „odchodziæ od stron ojczystych” \t d. „religi zostawiaæ lesistych”\n";
    odpowiedzi[90] = 'c';
    pytania[91] = "Co ³¹czy rowerowa szprycha?:\na. obrêcz z dêtk¹ \t b. dêtkê z piast¹ \nc. piastê z obrêcz¹ \t d. obrêcz z widelcem\n";
    odpowiedzi[91] = 'c';
    pytania[92] = "Suspens to chwyt stosowany:\na. w zapasach \t                 b. w grze na gitarze \nc. we wspinaczce klasycznej \t d. w filmach\n";
    odpowiedzi[92] = 'd';
    pytania[93] = "Lew zabity przez Ramona Marcedera to:\na. Simba \t b. To³stoj \nc. Trocki \t d. Mufasa\n";
    odpowiedzi[93] = 'c';
    pytania[94] = "Który z wymienionych nie wyst¹pi³ w filmie fabularnym przed prezydentur¹?:\na. Donald Trump \t b. Ronald Reagan \nc. Lech Kaczyñski \t d. Valcav Havel\n";
    odpowiedzi[94] = 'd';
    pytania[95] = "Jak nazywa siê amerykañska baza wojskowa na Kubie?:\na. Santa Clara \t b. Bayamo \nc. Guantanamo \t d. Matanzas\n";
    odpowiedzi[95] = 'c';
    pytania[96] = "Gdzie produkowany jest od 1835 roku w³oski wermut Cinzano (rodzaj wina)?:\na. w Turynie \t         b. w Wenecji \nc. w Mediolanie \t d. we Florencji\n";
    odpowiedzi[96] = 'a';
    pytania[97] = "Kto by³ malarzem króla Filipa IV Habsburga?:\na. Marcello Bacciarelli \t b. Jan van Eyck \nc. Diego Velázquez \t         d. Jacques-Louis David\n";
    odpowiedzi[97] = 'c';
    pytania[98] = "Ile to jest 1111 razy 1111, jeœli 1 razy 1 to 1, a 11 razy 11 to 121?:\na. 12321 \t b. 1 234 321 \nc. 111 111 111 \t d. 123 434 321\n";
    odpowiedzi[98] = 'b';
    pytania[99] = "Symbol waluty euro to stylizowana grecka litera. Która?:\na. beta \t b. heta \nc. eta \t         d. epsilon\n";
    odpowiedzi[99] = 'd';





    pytaniapolnapol[1] = "Który z tych u³amków to u³amek niew³aœciwy?:\n-. 3/4\tb. 0,3\nc. 4/3\t-. 0,33\n";
    pytaniapolnapol[2] = "Twarz i poca³unek to?:\n-. morda\tb. ca³us\n-. cmok \td. buziak\n";
    pytaniapolnapol[3] = "Do czego s³u¿y krawcowej blaszka na palec?:\na. do ochrony palca\t         -. do prucia fastryg\n-. do obrzucania dziurek\t d. do nawlekania igie³\n";
    pytaniapolnapol[4] = "Wska¿ b³¹d.:\n-. wymyœliæ coœ naprêdce\t -. schodziæ na manowce\nc. nadwerê¿yæ plecy\t         d. poddaæ coœ w w¹tpliwoœæ\n";
    pytaniapolnapol[5] = "K³óciæ siê z kimœ, robiæ mu na z³oœliwoœci to pójœæ z nim:\n-. w sukurs\t -. jak w dym\nc. w konkury\t d. na udry\n";
    pytaniapolnapol[6] = "Co ma lodowiec?:\n-. ga³y\t b. jêzor\nc. girê\t -. ka³dun\n";
    pytaniapolnapol[7] = "Polskie ruskie pierogi nadziewane s¹?:\n-. bia³¹ i czerwon¹ kapust¹\t b. bia³a i czerwon¹ fasol¹\n-. bia³ym i czerwonym miêsem\t d. ziemniakami i serem\n";
    pytaniapolnapol[8] = "W jakim mieœcie odbywa³y siê s³ynne spotkania naukowo-literackie zwane obiadami czwartkowymi?:\na. w GnieŸnie\t -. w Pu³awach\nc. w Warszawie\t -. w Krakowie\n";
    pytaniapolnapol[9] = "Kto napisa³ „Would you know my name if I saw you in heaven”I to œpiewa z gitar¹?:\n-. Soyka\t -. Phil Collins\nc. Eric Clapton\t d. Sting\n";
    pytaniapolnapol[10] = "Czego moga u¿yczyæ Dafne po przemianie?:\n-. laski wanilii\t b. listka bobkowego\n-. kryszta³u soli\t d. kory cynamonu\n";
    pytaniapolnapol[11] = "Na krechê:\na. powo³ywa³ siê T.Mazowiecki\t -. skacze temperatura\nc. zje¿d¿aj¹ narciarze\t         -. czeka³ przys³owiowy Matysek\n";
    pytaniapolnapol[12] = "Zagalopowaæ siê to posun¹æ siê:\n-. w latach\t -. nieco na koniu\nc. za daleko\t d. o w³os\n";
    pytaniapolnapol[13] = "Nie ma ¿adnych pañstw oœciennych:\n-. Polska\t -. Portugalia\nc. Serbia\t d. Islandia\n";
    pytaniapolnapol[14] = "Który instrument stroi muzyk?:\n-. tamburyn\t b. kocio³\nc. okarynê\t -. czynele\n";
    pytaniapolnapol[15] = "Z gry na jakim instrumencie s³ynie Czes³aw Mozil?:\n-. na kornecie\t b. na akordeonie\nc. na djembe\t -. na saksofonie\n";
    pytaniapolnapol[16] = "Co ukoi nerwy i zast¹pi cytrynê?:\na. melisa lekarska\t -. miêta pieprzowa\nc. jaskó³cze ziele\t -. ziele angielskie \n";
    pytaniapolnapol[17] = "Co kroimy w piórka?:\na. cebulê\t -. natkê pietruszki\nc. buraki\t -. seler naciowy \n";
    pytaniapolnapol[18] = "Jaki kolor ma dodawany do gum do ¿ucia, pasta do zêbów, cukru pudru i wielu innych produktów dwutlenku tytanu?:\na. zielony\t -. czerwony\n-. czarny\t d. bia³y \n";
    pytaniapolnapol[19] = "Wszystkie œmieci rozk³adaj¹ siê kilkaset lat, ale najd³u¿ej:\n-. pampers\t         b. plastikowa torebka\nc. ¿y³ka wêdkarska\t -. aluminiowa puszka \n";
    pytaniapolnapol[20] = "Który z indeksów reprezentuje Gie³dê Papierów Wartoœciowych w Warszawie?:\n-. DAX\t b. NASDAQ\nc. WIG\t -. Dow Jones \n";
    pytaniapolnapol[21] = "Politycy ³¹cz¹ w popularna piramidkê:\n-. mandaty poselskie\t b. proletariuszy wszystkich krajów\nc. palce d³oni\t         -. punkty wyst¹pienia \n";
    pytaniapolnapol[22] = "Jaka czêœæ mowy odpowiada na pytaniapolnapol: kto, co?:\n-. przymiotnik\t b. czasownik\nc. rzeczownik\t -. przys³ówek \n";
    pytaniapolnapol[23] = "Co powstanie z wody, gdy j¹ zamrozimy?:\na. para\t -. chmura\nc. lód\t -. mleko \n";
    pytaniapolnapol[24] = "Jaka legenda jest zwi¹zana z Warszaw¹?:\na. o smoku wawelskim \t                 -. o Popielu\n-. o Wandzie, co nie chcia³a Niemca\t d. o syrence \n";
    pytaniapolnapol[25] = "Kto ma ³eb obdarty?:\n-. kto póŸno przychodzi  \t b. kto jest krótko ostrzy¿ony \nc. kto gra w karty \t         -. kto ma nos zadarty \n";
    pytaniapolnapol[26] = "Jak siê pisze wyraz (rz/¿)(ó/u)raw? :\n-. ¿, ó   \t -. rz, u  \nc. rz, u  \t d. ¿, u \n";
    pytaniapolnapol[27] = "Co nie jest nazw¹ stylu p³ywackiego?:\na. rekin \t -. kraul \n-. ¿abka \t d. delfin \n";
    pytaniapolnapol[28] = "Która z tych ma³p jest najwiêksza?:\n-. orangutan \t -. kapucynka \nc. szympans \t d. goryl \n";
    pytaniapolnapol[29] = "Jaki jest numer stra¿y po¿arnej?:\n-. 999 \t b. 997 \nc. 998 \t -. 996 \n";
    pytaniapolnapol[30] = "W jakim mieœcie jest Wawel?:\n-. we Wroc³awiu \t b. w Warszawie \n-. w Poznaniu \t         d. w Krakowie \n";
    pytaniapolnapol[31] = "Gdzie le¿y Arktyka?:\na. wokó³ bieguna po³udniowego \t b. wokó³ bieguna pó³nocnego \n-. na równiku \t                 -. na Ksiê¿ycu \n";
    pytaniapolnapol[32] = "Trzy z czterech nazw odnosz¹ siê do tego samego oceanu. Która go nie dotyczy?:\na. Atlantyk \t -. Ocean Wielki \nc. Pacyfik \t -. Spokojny \n";
    pytaniapolnapol[33] = "Które ze œwi¹t dzieli najmniejsza liczba dni od Andrzejek?:\na. Bo¿e Narodzenie \t -. Wielkanoc \nc. Zaduszki \t         -. Œwiêto Trzech Króli \n";
    pytaniapolnapol[34] = "Ile rodzonych córek mia³a macocha Kopciuszka w baœni braci Grimm?:\na. dwie \t b. trzy \n-. cztery \t -. piêæ \n";
    pytaniapolnapol[35] = "Jak to dalej sz³o? „Opowiem ci bajkê, jak kot pali³ fajkê, a kocica papierosa… :\n-. kociêta zaœ skrêta \t b. w fifce, byle dalej nosa \nc. upali³a kawa³ nosa \t -. te koty zesz³y z drogi cnoty \n";
    pytaniapolnapol[36] = "Czym Chiñczycy tradycyjnie jadaj¹ potrawy z ry¿u?:\na. ³y¿kami \t -. wyka³aczkami \n-. widelcami \t d. pa³eczkami \n";
    pytaniapolnapol[37] = "Ile miesiêcy liczy kwarta³?:\n-. 2 \t b. 3 \nc. 4 \t -. 5 \n";
    //srednie
    pytaniapolnapol[38] = "Kim z zawodu jest Frank Underwood – g³ówny bohater serialu „House of Cards?:\n-. kierowc¹ rajdowym \t b. architektem \nc. politykiem \t         -. pokerzyst¹ \n";
    pytaniapolnapol[39] = "S¹¿eñ to antropometryczna miara d³ugoœci równa rozpiêtoœci:\na. piêt \t          b. ramion \n-. ramion cyrkla \t  -. zainteresowañ \n";
    pytaniapolnapol[40] = "Co jest charakterystyczne w umaszczeniu doga niemieckiego zwanego arlekinem?:\na. czarna podpalana sierœæ \t  -. równo rozmieszczone prêgi \nc. czarne ³aty na bia³ym tle \t  -. jednolity z³oty kolor \n";
    pytaniapolnapol[41] = "Dziko roœnie w Polsce i jest lian¹:\n-. aktinidia smakowita \t  b. bluszcz pospolity \n-. malina w³aœciwa \t  d. grab \n";
    pytaniapolnapol[42] = "W papieskim b³ogos³awieñstwie „Urbi et Orbi” - urbi znaczy miastu, a orbi?:\n-. wsi \t          b. œwiatu \nc. s³oñcu \t  -. obie¿yœwiatom \n";
    pytaniapolnapol[43] = "S³ynne zwierzê senator za panowania cesarza Kaliguli to:\na. koñ \t          -. w¹¿ \n-. kozio³ \t  d. kanarek \n";
    pytaniapolnapol[44] = "Który z pó³wyspów nie ma sta³ych rzek?:\na. Pó³wysep Skandynawski \t -. Pó³wysep Jutlandzki \n-. Pó³wysep Indyjski \t         d. Pó³wysep Arabski \n";
    pytaniapolnapol[45] = "Co ma ³apawica?:\n-. brak zahamowañ \t         b. „futera³” na kciuk \nc. sta³y potencja³ infekcyjny \t -. sk³adany miech \n";
    pytaniapolnapol[46] = "Jan Kochanowski po œmierci Zygmunta Augusta by³ zwolennikiem i uczestniczy³ w elekcji:\na. Augusta III Sasa \t -. Jana III Sobieskiego \n-. Jana II Kazimierza \t d. Henryka Walezego \n";
    pytaniapolnapol[47] = "Okulbaczyæ to:\na. sprawiæ sobie binokle \t -. zaszczepiæ drzewko \n-. kontrolowaæ okulistów \t d. osiod³aæ wierzchowca \n";
    pytaniapolnapol[48] = "Która z biblijnych postaci nosi przydomek Iskariota?:\n-. Moj¿esz \t b. Judasz \nc. Noe \t         -. Abel \n";
    pytaniapolnapol[49] = "Których bierek w bierkach jest najwiêcej?:\n-. wiose³ \t -. bosaków \nc. trójzêbów \t d. oszczepów \n";
    pytaniapolnapol[50] = "Wszystkie cztery brzmi¹ tak samo, a jedno wygl¹da i brzmi inaczej odwo³uje siê do prawdy. Które?:\n-. bana³ \t -. komuna³ \nc. frazes \t d. truizm \n";
    pytaniapolnapol[51] = "Komiksowym 'dzieckiem' rysownika Boba Kane'a jest:\n-. Superman \t b. Batman \nc. Spider-Man \t -. Captain Ameryka \n";
    pytaniapolnapol[52] = "Likier maraskino produkuje siê z maraski, czyli odmiany:\na. wiœni \t -. jab³oni \nc. figi \t -. gruszy \n";
    pytaniapolnapol[53] = "Który utwór Juliusza S³owackiego napisany jest proz¹?:\na. „Godznia myœli” \t -. „W Szwajcarii” \nc. „Anhelli” \t         -. „Arabi” \n";
    pytaniapolnapol[54] = "Który ssak siê nie spoci?:\n-. owca \t b. koñ \n-. cz³owiek \t d. królik \n";
    pytaniapolnapol[55] = "Kogo dotyczy gamofobia?:\n-. kandydatów do pracy \t         b. przysz³ych ma³¿onków \nc. uczniów przed matur¹ \t -. graczy na gie³dzie \n";
    pytaniapolnapol[56] = "Pad to najd³u¿sza rzeka:\n-. Hiszpanii \t b. Portugalii \n-. Grecji \t d. W³och \n";
    pytaniapolnapol[57] = "Który smerf ma na ramieniu wytatuowane serce przebit¹ strza³¹?:\n-. maruda \t b. osi³ek \nc. wa¿niak \t -. ciamajda \n";
    pytaniapolnapol[58] = "Co t³usty krem potrafi zostawiæ na skórze?:\n-. koncert \t         -. sztukê \nc. operê mydlan¹ \t d. film \n";
    pytaniapolnapol[59] = "Za co przytulaj¹ hajs snugglersi?:\na. za przytulanie \t -. za lanie \nc. za kasê \t         -. za masê \n";
    pytaniapolnapol[60] = "Kogo uratowa³a Calineczka?:\n-. kreta \t b. jaskó³kê \n-. pingwina \t d. ¿abê \n";
    pytaniapolnapol[61] = "Ile jest znaków zodiaku?:\na. 12  \t -. 15 \n-. 16 \t d. 10 \n";
    pytaniapolnapol[62] = "Do ilu punktów liczy siê set w tenisie sto³owym?:\na. 11  \t -. 25 \n-. 31 \t d. 21 \n";
    pytaniapolnapol[63] = "Jakie s¹ najwy¿sze góry na œwiecie?:\n-. Tatry \t b. Himalaje \n-. Pireneje \t d. Alpy \n";
    pytaniapolnapol[64] = "Który z podanych instrumentów nie nale¿y do grupy aerofonów?:\n-. obój \t -. tuba \nc. dudy \t d. ¿ele \n";
    pytaniapolnapol[65] = "Wafel pieczony z delikatnego ciasta w specjalnych foremkach to:\n-. bajgiel \t b. andrut \nc. bak³awa \t -. beza \n";
    pytaniapolnapol[66] = "Które z okreœleñ nie oznacza wys³annika?:\na. emisariusz \t -. kurier \n-. pose³ \t d. ordyna \n";
    pytaniapolnapol[67] = "Tytu³owa wataha z serialu wyre¿yserowanego miêdzy innymi przez Kasiê Adamik to:\n-. wilcza rodzina \t b. rosyjscy szpiedzy \nc. stra¿nicy graniczni \t -. uchodŸcy ze Wschodu \n";
    //trunde
    pytaniapolnapol[68] = "Jaki instrument wykorzysta³ wêdrowny szczuro³ap, który w XIII wieku mia³ wyprowadziæ szkodniki z Hameln?:\n-. Bêben \t b. Flet \nc. Puzon \t -. Harfê \n";
    pytaniapolnapol[69] = "Konne tramwaje najwczeœniej pojawi³y siê w Warszawie, a elektryczne?:\na. te¿ w Warszawie \t -. w Bytomiu \n-. w Krakowie \t         d. we Wroc³awiu \n";
    pytaniapolnapol[70] = "Wyrazy srebro i pieni¹dze brzmi¹ tak samo, ale tylko:\n-. po niemiecku \t -. po rosyjsku \nc. po angielsku \t d. po francusku \n";
    pytaniapolnapol[71] = "Przyk³adem transhumancji jest:\na. wypêdzanie owiec na hale \t -. klonowanie zwierz¹t \nc. mit o Minotaurze \t         -. galwanizowanie trupa \n";
    pytaniapolnapol[72] = "Symultanê rozgrywa siê:\n-. w tenisie ziemnym \t b. w szachach \nc. w zapasach \t         -. w pi³ce no¿nej \n";
    pytaniapolnapol[73] = "W 1937 r. w ramach pomocy genera³owi Franco baskijsk¹ stolicê Guernicê prawie do cna zniszczy³y bombardowania:\na. Luftwaffe \t                 -. Wojenno-Wozdusznych Si³ \n-. United States Air Forces \t d. Royal Air Force \n";
    pytaniapolnapol[74] = "Na szlaku Orlich Gniazd natrafimy na liczne zamki obronne budowane na skalistych, wapiennych wzgórzach. Jednym z nich jest zamek:\na. w Olsztynie \t b. w GnieŸnie \n-. w Malborku \t -. w £añcucie \n";
    pytaniapolnapol[75] = "„Jako to œwiadczymy, jako Anka zabi³a Maciejowi wieprz i na w¹grodzie mu nie da³a paœæ” – to wyimek z tekstu:\n-. roty wojskowej \t b. roty s¹dowej \n-. roty œlubnej \t d. „Roty” Marii Konopnickiej \n";
    pytaniapolnapol[76] = "Kto jest mistrzem tego samego orê¿a, w jakim specjalizowa³a siê mitologiczna Artemida?:\n-. Zorro \t b. Legolas \nc. Don Kichot \t -. Longinus Podbipiêty \n";
    pytaniapolnapol[77] = "O ile oczu mniej ma mitologiczny Polifem od mitologicznego olbrzyma Argusa?:\na. o dziewiêædziesi¹t dziewiêæ \t -. o dziewiêædziesi¹t osiem \n-. o jedno \t                 d. o dwoje \n";
    pytaniapolnapol[78] = "Sk¹d pochodzi³ Conan Barbarzyñca?:\n-. z Rivii \t -. z Oz \nc. z Mordoru \t d. z Cimmerii \n";
    pytaniapolnapol[79] = "Co wed³ug Leszka Ko³akowskiego jest sklepieniem domu, w którym duch ludzki mieszka?:\n-. Rozum \t b. Bóg \n-. Mi³oœæ \t d. Czas \n";
    pytaniapolnapol[80] = "Odra¿aj¹cy drab z Kabaretu Starszych Panów dubeltówkê weŸmie, wyjdzie i...:\n-. rach-ciach! \t b. buch, buch! \nc. z rur dwór \t -. bum w brzuch \n";
    pytaniapolnapol[81] = "Co widnieje na fladze Azorów?:\n-. pies \t b. psy \nc. jastrz¹b \t -. jastrzêbie\n";
    pytaniapolnapol[82] = "Ró¿añcow¹ tajemnic¹ chwalebn¹ nie jest...:\n-. Wniebowziêcie Matki Boskiej \t b. Zmartwychwstanie Jezusa \nc. Œmieræ Jezusa na krzy¿u \t -. Zes³anie Ducha Œwiêtnego\n";
    pytaniapolnapol[83] = "Tylko jedno zawiera utarty zwrot. Które?:\n-. zebra pasi siê na pasach \t b. droga je¿y siê trudnoœci¹ \nc. licha lisi siê sprytem \t -. jêki zajêcz¹ siê ¿a³oœnie\n";
    pytaniapolnapol[84] = "Choroba ³okcia dotycz¹ca miêœni zginaczy, na któr¹ cierpi¹ dentyœci, ksiêgowi i informatycy, to tak zwany ³okieæ:\na. golfisty \t -. kierowcy kabrioletu \nc. p³ywaka \t -. skoczka narciarskiego\n";
    pytaniapolnapol[86] = "Jaki jest kod pocztowy Kluczborku?:\na. 46-203 \t -. 43-370 \nc. 46-201 \t -. 40-200\n";
    pytaniapolnapol[87] = "Na akord mo¿na:\n-. spaæ \t b. pracowaæ \n-. œpiewaæ \t d. podró¿owaæ\n";
    pytaniapolnapol[88] = "Co kaftan bezpieczeñstwa ma znacznie d³u¿sze ni¿ zwyk³y kaftan?:\n-. przód \t b. rêkawy \nc. ty³ \t         -. ko³nierz\n";
    pytaniapolnapol[89] = "Kto na igrzyskach olimpijskich w Pjongczangu nie móg³ startowaæ pod flag¹ w³asnego kraju?:\na. Kanadyjczycy \t -. Szwedzi \nc. Rosjanie \t         -. Chiñczycy\n";
    pytaniapolnapol[90] = "Jak to dalej sz³o? „Góralu, czy ci nie ¿al…:\n-. „na wódkê wydawaæ szmal” \t         -. „podrzucaæ lasów i hal” \nc. „odchodziæ od stron ojczystych” \t d. „religi zostawiaæ lesistych”\n";
    pytaniapolnapol[91] = "Co ³¹czy rowerowa szprycha?:\na. obrêcz z dêtk¹ \t -. dêtkê z piast¹ \nc. piastê z obrêcz¹ \t -. obrêcz z widelcem\n";
    pytaniapolnapol[92] = "Suspens to chwyt stosowany:\n-. w zapasach \t                 b. w grze na gitarze \n-. we wspinaczce klasycznej \t d. w filmach\n";
    pytaniapolnapol[93] = "Lew zabity przez Ramona Marcedera to:\na. Simba \t -. To³stoj \nc. Trocki \t -. Mufasa\n";
    pytaniapolnapol[94] = "Który z wymienionych nie wyst¹pi³ w filmie fabularnym przed prezydentur¹?:\na. Donald Trump \t -. Ronald Reagan \n-. Lech Kaczyñski \t d. Valcav Havel\n";
    pytaniapolnapol[95] = "Jak nazywa siê amerykañska baza wojskowa na Kubie?:\na. Santa Clara \t -. Bayamo \nc. Guantanamo \t -. Matanzas\n";
    pytaniapolnapol[96] = "Gdzie produkowany jest od 1835 roku w³oski wermut Cinzano (rodzaj wina)?:\na. w Turynie \t         -. w Wenecji \nc. w Mediolanie \t -. we Florencji\n";
    pytaniapolnapol[97] = "Kto by³ malarzem króla Filipa IV Habsburga?:\na. Marcello Bacciarelli \t -. Jan van Eyck \nc. Diego Velázquez \t         -. Jacques-Louis David\n";
    pytaniapolnapol[98] = "Ile to jest 1111 razy 1111, jeœli 1 razy 1 to 1, a 11 razy 11 to 121?:\n-. 12321 \t b. 1 234 321 \nc. 111 111 111 \t -. 123 434 321\n";
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
         odpowiedzi_string += odpowiedzi_pobrane[i]; //zamienia tablicê stringów na jednego stringa
     }
     strcpy_s(odpowiedzi, odpowiedzi_string.c_str()); //zamienia stringa na tablicê charów
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
MENU: cout << "Witaj w MILIONERACH!\n 1. Klasyczny tryb gry milionerzy\n 2. Tryb z dowoln¹ ilosci¹ pytan\n 3. Zasady \n 4. Wyniki\n";
    char a;   
wybor: 
    cout << "Wybierz opcje z menu\n";
    cin >> a;

        switch (a) {
        case '1':
            wyniki.open("wyniki.txt", ios::out | ios::app); //otwarcie pliku tekstowego z wynikami
            cout << "Proszê podaæ nick: ";
            cin >> nick;
            system("cls");
            //pierwsze pytanie
        ponowne_losowanie_pierwszego:  index = rand() % 37 + 1;
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "Pytanie 1:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³ <- |\n";
            cout << " =====================\n";
            char odp;
        powrot_do_pierwszego:  
            cin >> odp;
            odp = char(tolower(odp));

            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 500z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == '0') {
                system("cls");
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 0 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 0 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_pierwszego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_pierwszego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 1:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda: 500z³!\n";
                else
                {
                    goto porazka_w_pierwszym;
                }
            }
            else {
            porazka_w_pierwszym:  
                cout << "B³êdna odpowiedŸ. Wygrywasz 0 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 0 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //drugie pytanie
        ponowne_losowanie_drugiego:  index = rand() % 37 + 1;
            cout << "Pytanie 2:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³ <- |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_drugiego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda gwarantowana: 1000z³.\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 500 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 500 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_drugiego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_drugiego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 2:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda: 1000z³!\n";
                else
                {
                    goto porazka_w_drugim;
                }
            }
            else {
            porazka_w_drugim: cout << "B³êdna odpowiedŸ. Wygrywasz 0 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 0 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //trzecie pytanie
        ponowne_losowanie_trzeciego:  index = rand() % 30 + 38;
            cout << "Pytanie 3:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³ <- |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";;
        powrot_do_trzeciego: cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 2 000z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 1 000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 1 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_trzeciego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_trzeciego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 3:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda: 2000z³!\n";
                else
                {
                    goto porazka_w_trzecim;
                }
            }
            else {
            porazka_w_trzecim:  cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od drugiego pytania 1 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl;
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //czwarte pytanie
        ponowne_losowanie_czwartego:  index = rand() % 30 + 38;
            cout << "Pytanie 4:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³ <- |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_czwartego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 5000z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 2000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 2 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_czwartego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_czwartego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 4:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda: 5 000z³!\n";
                else
                {
                    goto porazka_w_czwartym;
                }
            }
            else {
            porazka_w_czwartym: cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od drugiego pytania 1 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //piate pytanie
        ponowne_losowanie_piatego:  index = rand() % 30 + 38;
            cout << "Pytanie 5:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³ <- |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_piatego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 10 000z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 5 000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 5 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_piatego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_piatego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 5:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda: 10 000z³!\n";
                else
                {
                    goto porazka_w_piatym;
                }
            }
            else {
            porazka_w_piatym: cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od drugiego pytania 1 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //szoste pytanie
        ponowne_losowanie_szostego:  index = rand() % 30 + 38;
            cout << "Pytanie 6:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³ <- |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_szostego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 20 000z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 10 000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 10 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_szostego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_szostego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 6:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda: 20 000z³!\n";
                else
                {
                    goto porazka_w_szostym;
                }
            }
            else {
            porazka_w_szostym: cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od drugiego pytania 1 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //siodme pytanie
        ponowne_losowanie_siodmego:  index = rand() % 30 + 38;
            cout << "Pytanie 7:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³ <- |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_siodmego:   cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 40 000z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 20 000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 20 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_siodmego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_siodmego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 7:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda gwarantowana: 40 000z³!\n";
                else
                {
                    goto porazka_w_siodmym;
                }
            }
            else {
            porazka_w_siodmym: cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od drugiego pytania 1 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //osme pytanie
        ponowne_losowanie_osmego:   index = rand() % 32 + 68;
            cout << "Pytanie 8:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³ <- |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_osmego:   cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 75 000z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 40 000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 40 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_osmego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_osmego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 8:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda : 75 000z³!\n";
                else
                {
                    goto porazka_w_osmym;
                }
            }
            else {
            porazka_w_osmym: cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od siódmego pytania 40 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //dziewiate pytanie
        ponowne_losowanie_dziewiatego: index = rand() % 32 + 68;
            cout << "Pytanie 9:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³ <- |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_dziewiatego:   cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 125 000z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 75 000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 75 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_dziewiatego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_dziewiatego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 9:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda : 125 000z³!\n";
                else
                {
                    goto porazka_w_dziewiatym;
                }
            }
            else {
            porazka_w_dziewiatym: cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od siódmego pytania 40 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //dziesiate pytanie
        ponowne_losowanie_dziesiatego:  index = rand() % 32 + 68;
            cout << "Pytanie 10:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³ <- |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_dziesiatego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 250 000z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 125 000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 125 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_dziesiatego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_dziesiatego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 10:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda : 250 000z³!\n";
                else
                {
                    goto porazka_w_dziesiatym;
                }
            }
            else {
            porazka_w_dziesiatym: cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od siódmego pytania 40 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //jedenaste pytanie
        ponowne_losowanie_jedynastego:  index = rand() % 32 + 68;
            cout << "Pytanie 11:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³    |\n";
            cout << "| 11:   500.000 z³ <- |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_jedynastego:   cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 500 000z³\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 250 000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 250 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_jedynastego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowiedŸ!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowiedŸ!\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_jedynastego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 11:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowiedŸ! Obecna nagroda : 500 000z³!\n";
                else
                {
                    goto porazka_w_jedynastym;
                }
            }
            else {
            porazka_w_jedynastym: cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od siódmego pytania 40 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //dwunaste pytanie
        ponowne_losowanie_dwunastego: index = rand() % 32 + 68;
            cout << "Pytanie 12:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z³ <- |\n";
            cout << "| 11:   500.000 z³    |\n";
            cout << "| 10:   250.000 z³    |\n";
            cout << "|  9:   100.000 z³    |\n";
            cout << "|  8:    75.000 z³    |\n";
            cout << "|  7:   *40.000 z³    |\n";
            cout << "|  6:    20.000 z³    |\n";
            cout << "|  5:    10.000 z³    |\n";
            cout << "|  4:     5.000 z³    |\n";
            cout << "|  3:     2.000 z³    |\n";
            cout << "|  2:    *1.000 z³    |\n";
            cout << "|  1:       500 z³    |\n";
            cout << " =====================\n";
        powrot_do_dwunastego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "GRATULACJE!!!\n";
                cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 500 000 z³!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 500 000 z³" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju¿ zamiany pytania. Proszê podaæ odpowiedŸ:";
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
                    cout << "Nie posiadasz ju¿ podwójnej odpowiedzi. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_dwunastego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podwójn¹ odpowiedŸ! \nProszê podaæ odpowiedŸ(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "GRATULACJE!!!\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowiedŸ.\nProszê podaæ odpowiedŸ(masz jeszcze jedn¹ szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "GRATULACJE!!!\n";
                        cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
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
                    cout << "Nie posiadasz ju¿ pó³ na pó³. Proszê podaæ odpowiedŸ:";
                    goto powrot_do_dwunastego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano pó³ na pó³! Wykluczam dwie b³êdne odpowiedzi:\n";
                cout << "Pytanie 12:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) {
                    cout << "GRATULACJE!!!\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                }
                else
                {
                    goto porazka_w_dwunastym;
                }
            }
            else {
            porazka_w_dwunastym: cout << "B³êdna odpowiedŸ. Wygrywasz gwarantowane od siódmego pytania 40 000 z³! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Iloœæ prawid³owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z³" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            break;
        case '2':
            cout << "Ile chcesz mieæ pytañ?:";
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
                    cout << "B³êdna odpowiedŸ. To twoja " << licznikZlychOdpowiedzi << " z³a odpowiedŸ\n";

                    if (licznikZlychOdpowiedzi == 3) {
                        system("cls");
                        cout << "KONIEC GRY! Pope³ni³eœ 3 b³êdy.";
                        break;
                    }
                }
            }
            break;
        case '3': //wyœwietlenie zasad
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

            {
                system("cls");
                cout << "===============================================================\n";
                cout << "INSTRUKCJA:\nDo wyboru masz dwa tryby gry:\n1) Klasyczni milionerzy \n2) Losowe pytania" << endl;
                cout << "W trybie klasycznym, rozgrywka wyglada jak lekko zmodyfikowana gra w milionerów.\nMamy 12 pytañ, 3 ko³a ratunkowe, kwoty gwaranowane oraz koniec gry w razie b³êdnej opdowiedzi.\nW ka¿dej chwili mo¿na wyjœæ z gry i zabraæ pieni¹dze, wpisuj¹c 0 zamiast literki z odpowiedzi¹.\nJeœli chcesz u¿yæ kó³ ratunkowych, wpisz 7/8/9, aby u¿yæ odpowiednio-zamiany pytania/podwójna odpowiedŸ/pó³ na pó³. \nW tym trybie wyniki s¹ zapisywane i mo¿na je potem odczytaæ" << endl;
                cout << "W trybie losowym, to u¿ytkownik decyduje na ile pytañ chce odpowiedzieæ, a nastêpnie ma 3 ¿ycia. W tym trybie nie ma kó³ ratunkowych ani nagród.\nW tym trybie wyniki nie s¹ zapisywane." << endl;
                cout << "Aby sprawdziæ wyniki z trybu klasycznego, wpisz w menu gry 4.\n";
                cout << "==============================================================\n";
                goto MENU;
                break;
            }
        case '4': //wyœwietlenie wyników
        {
            cout << "WYNIKI:" << endl;
            wyniki.open("wyniki.txt", ios::in);
            if (wyniki.good() == false) {
                cout << "Taki plik nie istnieje! Zagraj w trybie klasycznym minimum raz, aby mieæ wyniki!";
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
