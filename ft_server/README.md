FT_SERVER

Serveur utilisant la techonologie Docker utilisant les services wordpress, phpmyadmin sous debian.

Docker 
Docker permet de créer des environnements (appelées containers) de manière à isoler des applications. Il repose sur le kernel Linux et sur une fonctionnalité : les containers, que vous connaissez peut-être déjà sous le doux nom de LXC. L'idée est de lancer du code dans un environnement isolé. (pour que chacun travaille dans le meme environnement ou pour connaitre exactement les dependencies utilises pour le projet)

Docker et les containers Linux ne se comportent pas de la même manière qu'une VM. Une machine virtuelle isole tout un système (son OS), et dispose de ses propres ressources.

Dans le cas de  Docker, le kernel va partager les ressources du système hôte et interagir avec le(s) container(s). Techniquement, Docker n'est pas une VM, pas le moins du monde, mais en terme d'utilisation, Docker peut-être apparenté à une VM.

<p>
    <img src="docker-containers-vms.png"/>
</p>

Useful instructions for this project:
- List all containers (only IDs)
```
> docker ps -aq
```
- Stop all running containers
```
> docker stop $(docker ps -aq)
```
- Remove all containers
```
> docker rm $(docker ps -aq)
```
- Remove all images
```
> docker rmi $(docker images -q)
```
- Build image
```
> docker build -t ‘nomimage+tag’ .
```
- List all images
```
> docker images
```
- Run container
```
> docker run -d p 80:80 –name=’nomconteneur’ ‘nomimage’  (-P to expose to public ports randomly)
```
- Check the port
```
> docker port ‘nomconteneur’
```
- Enter to container
```
>docker exec it ‘nomconteneurouid’ bash
```
- check nginx error (inside container)
```
> tail -30 /var/log/nginx/error.log
> nginx -t
    ```