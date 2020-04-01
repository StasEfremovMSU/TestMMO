# TestMMO
Герман <br/><br/>
Карта - двумерный массив sell <br/>
Лежит как глобальная переменная mymap <br/>
Размер карты в map_mmo.cpp <br/>
Глобальная функция Print отрисоывает каждый шаг на экране
 <br/><br/>
 Cell <br/>
  Vector2 coordinate;<br/>
	bool food;<br/>
	void RandomFoodGenerate();<br/>
public:<br/>
	bool GetFood();<br/>
	void SetFood(bool x);<br/>
	Cell(int x , int y);<br/>
	Cell();<br/>
 <br/>
 Порядок наследования
 creature -> human -> human_grup
<br/>
<br/>
Что недоработано  <br/>
Отрисовка экрана требует введения символа с клавиатуры <br/>

