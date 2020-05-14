# Projeto Jogo Dino
Projeto apresentado na disciplina de algoritmos 2. <br>
Jogo inplementado em linguagem C, ou seja, interface grafica limitada, apenas o print com cmd padrão. <br>
A pontuação do jogo (score) é mostrada na parte de cima da tela e tem como base de incremento o pulo do personagem

## Funçoes utilizadas/produzidas:
<ul>
  <li>Kbhit()  Usado para verificar se tem alguma coisa em buffer de teclado, se sim o mesmo retorna 1</li>
  <li>System(“mode com: lines=29 cols=82”);  Faz com que a tela do cmd fique com proporção de 29 linhas por 82 colunas</li>
  <li>Getch()  Retorna o que tem no buffer.</li>
  <li>Setbuf(stdin, NULL);  atribui NULL ao buffer do teclado</li>
  <li>Void gotoxy(int x, int y)  Está função tem por finalidade fixar determinado texto nas coordenadas que são passadas para ela, para utilização é necessário usar a biblioteca Windows.h</li>
  <li>Void delay(int timems)  Está função faz com que seja gerado um delay no programa, a mesma foi programada para que o parâmetro passado seja em milissegundos</li>
  <li>Void iniciar()  Usada para setar algumas informações em um ponto fixo da tela</li>
    <li>Void dino( int pulo)  Usada para printar o personagem na tela e realizar a movimentação das “pernas”</li>
    <li>Char manip_object()  Aonde está implementado o sistema de colisão e é gerado os obstáculos.</li>
    <li>Char menu()  Switch/case para o menu inicial do jogo</li>
    <li>Void creditos()  código para abrir um arquivo txt com o texto de créditos</li>
</ul>

## Bugs:
<ul>
	<li>"Acumulo" de buffer </li>
	<li>Limitações gráficas</li>
	<li>Quando pressionado o X para sair apenas uma vez o mesmo não funciona no jogo, para tal funcionamento tem de ser pressionado a tecla duas vezes </li>
</ul>
