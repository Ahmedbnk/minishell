FROM gcc:14

RUN apt-get update && apt-get install -y \
    libreadline-dev \
    make

WORKDIR /app
COPY . .
RUN make
CMD ["./minishell"]
