# Parte 1:

Paradigma de programação é o estilo ou abordagem utilizada na escrita de código. A escolha de um paradígma não é definida pela linguagem de programação em si, contudo esta limitada a ela. As linguagens C e Fortran por exemplo, admitem o paradígma Procedural, mas como não tem classes, não permitem o uso do paradígma Orientação a Objetos. Por outro lado, linguagens mais versáteis como C++ e Java são consideradas multiparadígmas, pois permitem a escrita em mais de um estilo como Orientação a Objetos, programação Funcional e programação Procedural.

Liguagens de alto nível como C e Fortran, eliminam a necessidade do uso de goto, tipicamente utilizada em Assembly, uma vez que novos statments tornam a sintaxe mais amigáveis a programadores. Logo, estes conceitos juntamente com modularização, design top-down e tipagem são ideais para resolver problemas de computação científica, tipicamente encontrado em áreas como física, matemática e afins. 

Por outro lado, este estilo de programação procedural não permite encapsular dados, tornando softwares muito mais suscetíveis a efeitos colaterais. Além do mais, aquilo que no mundo real é expresso através de substantívos, sendo estes concretos ou abstratos, tem uma natureza incompatível com tipos utilizados em programação procedural. Enquanto que, para matemáticos, é imediata associação entre o tipo inteiro com números naturais, para outras áreas é difícil representar carros, estradas, chuva em termos de char, double, float ou qualquer outro tipo similar. 

Em situações como esta a Orientação a objeto é mais indicada, pois permite ao programador se expressar de tal forma, que torna o código mais próximo de objetos que os representam. Esta abordagem é muito utilizada em produtos comerciais e jogos, pois é constituída sobre os conceitos de abstração, encapsulamento, herança e polimorfismo, permitindo ocultar complexidade, restringir acesso a dados, extender classes e sobrescrever comportamentos de métodos.

Existe ainda uma nítida diferença quanto ao controle de fluxo, entre a abordagem Procedural e Orientada a objetos. Na primeira abordagem, o design top-down, faz com que blocos de código, de forma consecutiva realizem suas tarefas e passem para as próximas até que execução do programa termine. Porém, no segundo caso, podem ser utilizadas interfaces, que invertem o fluxo de execução. Na prática, isto é interessante para [transmitir a responsabilidade executar certos controles de fluxos a frameworks](https://en.wikipedia.org/wiki/Dependency_injection), e assim criar componentes independentes para reduzir o acoplamento de código.

Para ilustrar estes conceitos, vou apresentar dois casos em que é conveniente o uso do paradígma Procedural e Orientado a Objeto. 

## 1- Procedural
Suponhamos que seja solicitado um programa que calcule as raízes de uma equação de segundo grau do tipo $ax^2 + bx + c$. Neste caso, teremos sempre duas raízes, mesmo que elas passem no mesmo ponto ou sejam complexas. Sendo assim, dado a natureza do problema, por se tratar simples expressões algébricas, não há necessidade de criar variáveis membro ou globais, pois a saída de uma função/método pode servir como parâmetro para outra. Além do mais, mesmo na abordagem procedural, é possível ocultar funções/métodos que não são essenciais nos níveis mais elevados do design top-down, mesmo sem a utilização de classes. 

Para implementar este programa que calcula raízes de equações de segundo grau, considere [este](https://github.com/EBAC-aluno/modulo6/tree/main/C) código escrito em linguagem C, no qual não há variáveis globais e é estruturado em funções disponíveis em alguns arquivos. Note que os arquivos header expõem somente aqueles métodos que precisam ficar visíveis para outros módulos do programa, o que os tornam mais legíveis e de fácil manutenção.

## 2- Orientação a Objeto

Considere um programa que constrói veículos personalizados. Então, na etapa de produção, o carro será entregue conforme a marca especificada e toda complexidade de produção fica oculta nos módulos responsáveis por construí-lo. Já para personalizá-lo, o carro é visto como um insumo para aplicação de uma nova cor.

Neste contexto e consideranto o possível uso do estilo procedural, nos deparamos com alguns problemas. Um deles é que um carro é composto por inúmeras peças com suas funcionalidades, fazendo com que fique difícil gerenciar tudo isso sem um encapsulamento adquado. O outro problema, é que isso gera um acoplamento desnecessário, pois a cor com que o carro será pintado, independe da sua marca e modelo. 

Sendo assim, a abodagem de Orientação a Objetos é mais adequada, pois as peças, assim como o carro, podem ser melhor representados por classes com uma devida visibilidade de seus métodos atributos. Além do mais, podemos utilizar uma interface para atribuir a responsabilidade de contrução a um módulo e utilizar o carro como objeto para aplicação de uma pintura personalizada. Veja [aqui](https://github.com/EBAC-aluno/modulo6/tree/main/Java) um programa simples escrito em Java que exemplifica este cenário.

# Parte 2:
```
inicio_do_algoritimo_acordar

dia = pegaODiaNoCalendario

se dia == domingo 
  horarioDeAcordar = 10
  senao
  horarioDeAcordar = 6
fim do se

hora = 0
enquanto hora < horarioDeAcordar
  dorme
  hora = hora + 1
fim do enquanto

abra os olhos
espreguiça 
boceja
coça o rosto
levanta

diga "Hoje é ${dia} e acordei ás ${hora} horas."

fim_do_algoritimo
