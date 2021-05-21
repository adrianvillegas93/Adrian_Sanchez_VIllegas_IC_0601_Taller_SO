#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuarios a agregar..."
   exit 1
fi

# Del archivo con el listado de usuarios a agregar:
# Este es el formato:
# ejemplo0:9010_fher:575:1001:FERNANDO MERCADO:/home/ejemplo0:bin/bash:
#    |         |      |    |           |              |           |
#    f1        f2     f3   f4          f5             f6          f7
#$f1 = username
#$f2 = password
#$f3 = user id
#$f4 = group id
#$f5 = user id info
#$f6 = home directory
#$f7 = comand shell

agregarUsuario(){
	#echo "----> Agregar Usuario <----"
	eval USERNAME="$1"
	eval PASSWORD="$2"
	eval USER_ID="$3"
	eval GROUP_ID="$4"
	eval USER_ID_INF="$5"
	eval HOME_DIRECTORY="$6"
	eval COMAND_SHELL="$7"
	
	#con grep buscamos un patron especifico el cual es el id del grupo, y que este se encuentre en la direccion /etc/group
	if grep -q ${GROUP_ID} /etc/group
	then
		echo "##############################################"
		echo "--------->CREANDO EL USUARIO<---------"
		echo "............................................"
		echo "EL grupo con el ID: "[${GROUP_ID}]" ya existe"
		#Aqui verificamos el grupo se encuentre en nuestra computadora
		
		#Lo mismo que con el id del grupo, solo que ahora buscamos el nombre de usuario en la direccion /etc/passwd
		if grep -q ${USERNAME} /etc/passwd
	  	then
	    		echo "EL usuario ya existe"
	    		echo "EL usuario con nombre de usuario "[${USERNAME}]" ya se encuentra agregado en el sistema"
	  	else
	    		echo "-------------------------------------------------------"
	    		echo "EL usuario "[${USERNAME}]" ha sido creado en el sistema"
	    		echo "La contraseña del usuario es: "[${PASSWORD}]" "
	    		echo "##############################################"
			
	    		#-d EL nuevo usuario se creara utilizando (HOME_DIR) como valor para el directorio de inicio de sesion del usuario
	    		#-g para obtener el id del grupo (gid)
	    		#-s para obtener el nombre del shell de inicio de sesión del usuario. 
	    		#-u Valor numerico de la identificacion del usuario, debe ser valor unico
	    		#-m para crear el directorio del usuario
	    		#-c Cualquier cadena de texto, breve descripcion del inicio de sesion
	    		useradd -g "${GROUP_ID}" -u "${USER_ID}" -m -d "${HOME_DIRECTORY}" "${USERNAME}" -c "${USER_ID_INF}" -s "${COMAND_SHELL}"
	    		#Para que al inicio de sesion, nos pida una contraseña, la cual actualizara a la anterior que era por defecto
	    		echo "$USERNAME:$PASSWORD" | chpasswd --md5
	    		chage -d 0 ${USERNAME}
	  	fi
	else
	  #Si el grupo no existe, no permitira crear el usuario
	  echo "............................................................................."
	  echo "El Usuario con el nombre de usuario "[${USERNAME}]" no fue agregado con exito"
	  echo "Ya que el grupo con indentificador "[${GROUP_ID}]" no existe"
	fi	
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
	agregarUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"	
done < ${file}

exit 0


