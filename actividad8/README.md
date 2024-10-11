# Despliegue de Kubernetes Local

## 1. Instalar un ambiente local de Kubernetes

### Usando Minikube:
1. Descargar e instalar Minikube:
   ```bash
   curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
   sudo install minikube-linux-amd64 /usr/local/bin/minikube

2. En un ambiente local de Kubernetes como los proporcionados por Minikube o Kind, técnicamente existen tanto nodos master como workers, pero estos se ejecutan en una misma máquina local. Kubernetes requiere al menos un nodo master para gestionar el clúster y los nodos workers para ejecutar los contenedores, pero en estos entornos locales, el nodo master y los nodos workers pueden estar integrados en un solo nodo. Esto facilita la administración y la experimentación en un entorno de desarrollo, sin la necesidad de múltiples máquinas físicas o virtuales.

En Minikube, por ejemplo, todo el clúster (master y worker) se ejecuta dentro de una máquina virtual o contenedor. Kind utiliza contenedores Docker para simular el clúster, donde cada contenedor actúa como un nodo de Kubernetes.

3. minikube start


### 2. Desplegar un contenedor de NGINX

1. Crear un archivo de despliegue (nginx-deployment.yaml):

                   
                    apiVersion: apps/v1
                    kind: Deployment
                    metadata:
                    name: nginx-deployment
                    spec:
                    replicas: 1
                    selector:
                        matchLabels:
                        app: nginx
                    template:
                        metadata:
                        labels:
                            app: nginx
                        spec:
                        containers:
                        - name: nginx
                            image: nginx:latest
                            ports:
                            - containerPort: 80


2. Aplicar el archivo de despliegue:

kubectl apply -f nginx-deployment.yaml

3. Exponer el servicio:

kubectl expose deployment nginx-deployment --type=NodePort --port=80

4. Obtener la URL del servicio:

minikube service nginx-deployment --url

### ¿En un ambiente local de Kubernetes existen los nodos masters y workers, cómo es que esto funciona?

1. En un entorno local de Kubernetes (Minikube o Kind), tanto los nodos masters como los workers están presentes, pero suelen estar combinados en una sola instancia, ejecutándose en la misma máquina local. Esto facilita el desarrollo y las pruebas sin necesidad de múltiples nodos físicos o virtuales.