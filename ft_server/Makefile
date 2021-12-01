build:
	docker build -t server .
run:
	docker run -d --name ft_server -p 80:80 -p 443:443 server
exec:
	docker exec -it ft_server /bin/bash
kill:
	docker kill ft_server
clean:
	docker rm ft_server
fclean: kill clean
