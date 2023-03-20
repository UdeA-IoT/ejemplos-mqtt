# Interfaz grafica


## Prerequisitos

## Instalación del entorno virtual

Inicialmente, se va a declarar un entorno virtual de desarrollo en python para ejecutar....


La proxima, teniendo en cuenta el archivo requeriments solo es necesario realizar el siguiente procedimiento:

```
python -m venv mqtt_env
.\mqtt_env\Scripts\activate # Windows
pip freeze > requirements.txt
deactivate
```

```
python -m venv mqtt_env
.\mqtt_env\Scripts\activate # Windows
pip install paho-mqtt
pip install pyserial
pip install "kivy[base]" kivy_examples
pip install kivymd
pip install python-dotenv
```



Luego se uso el comando:

```
pip freeze > requirements.txt
```

El arhivo requeriments queda como:

```
certifi==2022.12.7
charset-normalizer==3.1.0
docutils==0.19
idna==3.4
Kivy==2.1.0
kivy-deps.angle==0.3.3
kivy-deps.glew==0.3.1
kivy-deps.sdl2==0.4.5
Kivy-examples==2.1.0
Kivy-Garden==0.1.5
kivymd==1.1.1
paho-mqtt==1.6.1
Pillow==9.4.0
Pygments==2.14.0
pypiwin32==223
pyserial==3.5
python-dotenv==1.0.0
pywin32==305
requests==2.28.2
urllib3==1.26.15
```

Se trabaja y al final para salir del entorno tenemos:

```
deactivate
```

Volviendo a trabajar la proxima tenemos:

```
# Activar
.\mqtt_env\Scripts\activate # Windows

# Hacer cosas

# Salir
deactivate
```

Probando kyvi:

```
py .\mqtt_env\share\kivy-examples\demo\showcase\main.py
```



## Referencias

* https://docs.python-guide.org/dev/virtualenvs/
* https://rukbottoland.com/blog/tutorial-de-python-virtualenv/
* https://pythonbasics.org/virtualenv/
* https://realpython.com/python-virtual-environments-a-primer/
* https://learn.microsoft.com/es-es/windows/dev-environment/



